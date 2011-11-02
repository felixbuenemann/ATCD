// -*- C++ -*-
// $Id$

#include "tao/PortableServer/SUpcall_commands.h"
#include "tao/PortableServer/Servant_Base.h"

void
_is_a_Upcall_Command::execute (void)
{
  TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_arg_type retval =
    TAO::Portable_Server::get_ret_arg< ::ACE_InputCDR::to_boolean> (
      this->operation_details_,
      this->args_);

  TAO::SArg_Traits< char *>::in_arg_type arg_1 =
    TAO::Portable_Server::get_in_arg< char *> (
      this->operation_details_,
      this->args_,
      1);

  retval =
    this->servant_-> _is_a (
      arg_1);
}

void
_non_existent_Upcall_Command::execute (void)
{
  TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_arg_type retval =
    TAO::Portable_Server::get_ret_arg< ::ACE_InputCDR::to_boolean> (
      this->operation_details_,
      this->args_);

  retval =
    this->servant_-> _non_existent ();
}


void
_repository_id_Upcall_Command::execute (void)
{
  TAO::SArg_Traits< char *>::ret_arg_type retval =
    TAO::Portable_Server::get_ret_arg< char *> (
      this->operation_details_,
      this->args_);

  retval =
    this->servant_-> _repository_id ();
}


void
_get_component_Upcall_Command::execute (void)
{
//   TAO::SArg_Traits< ::CORBA::Object>::ret_arg_type retval =
//     TAO::Portable_Server::get_ret_arg< ::CORBA::Object> (
//       this->operation_details_,
//       this->args_);

//   retval =
//     this->servant_-> _get_component ();
}