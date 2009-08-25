// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.1 ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt Universityaaa
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:1278

#include "AMI_exec.h"
#include "AMI_perform_work.h"
#include "ciao/CIAO_common.h"


namespace CIAO_Hello_AMI_AMI_Impl
{
#if !defined (AMI_CORBA_IMPLEMENTATION)
  //============================================================
  // Implementation of the basic form of AMI: a thread to handle
  // asynchronous invocations.
  //============================================================
  AMI_thread_handler::AMI_thread_handler (
    ::CCM_AMI::Cookie ck,
    const char * in_str,
    ::CCM_AMI::AMI_foo_ptr foo_receiver,
    ::CCM_AMI::AMI_foo_callback_ptr foo_callback)
    : ck_ (ck),
      in_str_ (in_str),
      foo_receiver_ (::CCM_AMI::AMI_foo::_duplicate (foo_receiver)),
      foo_callback_ (::CCM_AMI::AMI_foo_callback::_duplicate (foo_callback))
  {
  }

  int AMI_thread_handler::svc ()
  {
    char* out_str;
    long  result;
    printf ("AMI :\tThread started for cookie <%ld> sending string <%s>\n", ck_, in_str_);
    result = foo_receiver_->asynch_foo (CORBA::string_dup (in_str_), out_str);
    printf ("AMI :\tCookie <%ld> received : result <%ld> answer <%s>\n",
            ck_, result, out_str);
    foo_callback_->foo_callback_handler (ck_, result, CORBA::string_dup (out_str));
    return 0;
  }
#else
  //============================================================
  // Implementation of the AMI CORBA reply handler
  //============================================================
  class AMI_reply_handler : public POA_CCM_AMI::AMI_AMI_fooHandler
  {
  public:
    AMI_reply_handler (::CCM_AMI::AMI_foo_callback_ptr foo_callback, long ck)
      : foo_callback_ (::CCM_AMI::AMI_foo_callback::_duplicate (foo_callback)),
        ck_ (ck)
    {
    };

    void foo (CORBA::Long result,
              const char * out_str)
      {
        printf ("AMI CORBA :\tHandler::asynch_foo\n");
        foo_callback_->foo_callback_handler (ck_, result, CORBA::string_dup (out_str));
        this->_remove_ref ();
      };

    void foo_excep (::Messaging::ExceptionHolder * excep_holder)
      {
        printf ("AMI CORBA :\tHandler::foo_excep\n");

        try
          {
            excep_holder->raise_exception ();
          }
        catch (const CCM_AMI::InternalError& ex)
          {
            printf ("AMI CORBA :\tCaught the correct exception type (CCM_AMI::InternalError) <%d> <%s> for cookie <%ld>\n",
                    ex.ex.id, ex.ex.error_string.in (), ck_);

            foo_callback_->foo_callback_excep (ck_, ex.ex);

            if (ex.ex.id != 42)
              {
                printf ("ERROR :\tReceived unexpected ID received in exception handler for cookie <%ld>\n",
                  ck_);
              }
            if (ACE_OS::strcmp (ex.ex.error_string.in (), "Hello world") != 0)
              {
                printf ("ERROR :\tReceived unexpected error string received in exception handler for cookie <%ld>\n",
                  ck_);
              }
          }
        catch (const CORBA::Exception& ex)
          {
            ex._tao_print_exception ("Caught the WRONG exception:");
          }
        this->_remove_ref ();
      };

    ~AMI_reply_handler (void)
    {
    };
  private:
    ::CCM_AMI::AMI_foo_callback_var foo_callback_;
    long ck_;
  };
#endif /* AMI_CORBA_IMPLEMENTATION */

  //============================================================
  // Facet Executor Implementation Class: AMI_ami_foo_exec_i
  //============================================================

#if !defined (AMI_CORBA_IMPLEMENTATION)
  AMI_ami_foo_exec_i::AMI_ami_foo_exec_i (
    ::CCM_AMI::AMI_foo_ptr foo_receiver,
    ::CCM_AMI::AMI_foo_callback_ptr foo_callback) :
      foo_receiver_ (::CCM_AMI::AMI_foo::_duplicate (foo_receiver)),
      foo_callback_ (::CCM_AMI::AMI_foo_callback::_duplicate (foo_callback)),
      cookie_ (0)
  {
  }
#else
  AMI_ami_foo_exec_i::AMI_ami_foo_exec_i (
    ::CCM_AMI::AMI_foo_callback_ptr foo_callback) :
      foo_callback_ (::CCM_AMI::AMI_foo_callback::_duplicate (foo_callback)),
      cookie_ (0)
  {
    //initialize AMI client
    int argc = 4;
    ACE_TCHAR **argv = new ACE_TCHAR *[argc];
    argv[0] = ACE::strnew (ACE_TEXT ("-ORBAMICollocation"));
    argv[1] = ACE::strnew (ACE_TEXT ("0"));
    argv[2] = ACE::strnew (ACE_TEXT ("-ORBDebugLevel"));
    argv[3] = ACE::strnew (ACE_TEXT ("5"));
    orb_ = CORBA::ORB_init (argc, argv, ACE_TEXT ("AMI client"));

    CORBA::Object_var object =
      orb_->string_to_object ("file://server.ior");
    ami_foo_var_ = CCM_AMI::AMI_foo::_narrow (object.in ());

    if (CORBA::is_nil (ami_foo_var_.in ()))
      {
        printf ("Server is NIL\n");
      }
    // Activate POA to handle the call back.
    CORBA::Object_var poa_object =
      orb_->resolve_initial_references("RootPOA");

    if (CORBA::is_nil (poa_object.in ()))
      printf ("POA is NIL!\n");

    PortableServer::POA_var root_poa =
      PortableServer::POA::_narrow (poa_object.in ());

    PortableServer::POAManager_var poa_manager =
      root_poa->the_POAManager ();

    poa_manager->activate ();
    AMI_perform_work *pw = new AMI_perform_work (orb_.in ());
    pw->activate ();
  }
#endif /* AMI_CORBA_IMPLEMENTATION */

  AMI_ami_foo_exec_i::~AMI_ami_foo_exec_i (void)
  {
  }

  // Operations from ::CCM_AMI::AMI_ami_foo

  ::CCM_AMI::Cookie
  AMI_ami_foo_exec_i::sendc_foo (
    const char * in_str)
  {
    printf ("AMI :\tsendc_foo <%s>\n", in_str);
    ::CCM_AMI::Cookie ck = ++cookie_;
#if !defined (AMI_CORBA_IMPLEMENTATION)
    //single thread to perform asynchronous actions
    printf ("AMI :\tReceived string <%s> for <%d>\n", in_str, ck);
    AMI_thread_handler* ah = new AMI_thread_handler (
        ck,
        in_str,
        foo_receiver_.in ()),
        foo_callback_.in ());
    ah->activate ();
#else
    //AMI CORBA implementation.
    printf ("Start the AMI CORBA handler thread\n");
    //start handler as a thread.
    AMI_reply_handler* handler = new AMI_reply_handler (foo_callback_.in (), ck);
    CCM_AMI::AMI_AMI_fooHandler_var the_handler_var = handler->_this ();
    printf ("AMI :\tSending string <%s> for cookie <%ld> to AMI CORBA server\n", in_str, ck);
    ami_foo_var_->sendc_foo (the_handler_var.in (), in_str);
    printf ("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
#endif /* AMI_CORBA_IMPLEMENTATION */
  return ck;
  }
  
  //============================================================
  // Component Executor Implementation Class: AMI_exec_i
  //============================================================
  
  AMI_exec_i::AMI_exec_i (void)
  {
  }
  
  AMI_exec_i::~AMI_exec_i (void)
  {
  }
  
  // Supported operations and attributes.
  
  // Component attributes.
  
  // Port operations.
  
  ::CCM_AMI::CCM_AMI_ami_foo_ptr
  AMI_exec_i::get_perform_asynch_foo (void)
  {
    ::CCM_AMI::AMI_foo_callback_var foo_callback =
      this->context_->get_connection_callback_foo ();

#if !defined (AMI_CORBA_IMPLEMENTATION)
    ::CCM_AMI::AMI_foo_var receiver_foo =
      this->context_->get_connection_receiver_foo ();
    return new AMI_ami_foo_exec_i (receiver_foo, foo_callback);
#else
    return new AMI_ami_foo_exec_i (foo_callback);
#endif /* AMI_CORBA_IMPLEMENTATION */
  }
  
  // Operations from Components::SessionComponent.
  
  void
  AMI_exec_i::set_session_context (
    ::Components::SessionContext_ptr ctx)
  {
    this->context_ =
      ::Hello_AMI::CCM_AMI_Context::_narrow (ctx);
    
    if ( ::CORBA::is_nil (this->context_.in ()))
      {
        throw ::CORBA::INTERNAL ();
      }
  }
  
  void
  AMI_exec_i::configuration_complete (void)
  {
    /* Your code here. */
  }
  
  void
  AMI_exec_i::ccm_activate (void)
  {
#if defined (AMI_CORBA_IMPLEMENTATION)
    ::CCM_AMI::AMI_foo_var receiver_foo =
      this->context_->get_connection_receiver_foo ();
    int argc = 2;
    ACE_TCHAR **argv = new ACE_TCHAR *[argc];
    argv[0] = ACE::strnew (ACE_TEXT (""));
    argv[1] = ACE::strnew (ACE_TEXT (""));
    CORBA::ORB_var orb =
      CORBA::ORB_init (argc, argv, ACE_TEXT ("AMI_server"));
    AMI_server *srv = new AMI_server (orb.in (), receiver_foo);
    printf ("AMI :\tStarting server thread.\n");
    srv->activate ();
#endif /* AMI_CORBA_IMPLEMENTATION */
  }
  
  void
  AMI_exec_i::ccm_passivate (void)
  {
    /* Your code here. */
  }
  
  void
  AMI_exec_i::ccm_remove (void)
  {
    /* Your code here. */
  }
  
  extern "C"  ::Components::EnterpriseComponent_ptr
  create_Hello_AMI_AMI_Impl (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_RETURN (
      retval,
      AMI_exec_i,
      ::Components::EnterpriseComponent::_nil ());
    
    return retval;
  }
}

namespace CIAO_Hello_AMI_AMI_Impl
{
  //============================================================
  // Home Executor Implementation Class: AMIHome_exec_i
  //============================================================
  
  AMIHome_exec_i::AMIHome_exec_i (void)
  {
  }
  
  AMIHome_exec_i::~AMIHome_exec_i (void)
  {
  }
  
  // All operations and attributes.
  
  // Factory operations.
  
  // Finder operations.
  
  // Implicit operations.
  
  ::Components::EnterpriseComponent_ptr
  AMIHome_exec_i::create (void)
  {
    ::Components::EnterpriseComponent_ptr retval =
      ::Components::EnterpriseComponent::_nil ();
    
    ACE_NEW_THROW_EX (
      retval,
      AMI_exec_i,
      ::CORBA::NO_MEMORY ());
    
    return retval;
  }
  
  extern "C"  ::Components::HomeExecutorBase_ptr
  create_Hello_AMI_AMIHome_Impl (void)
  {
    ::Components::HomeExecutorBase_ptr retval =
      ::Components::HomeExecutorBase::_nil ();
    
    ACE_NEW_RETURN (
      retval,
      AMIHome_exec_i,
      ::Components::HomeExecutorBase::_nil ());
    
    return retval;
  }
}

