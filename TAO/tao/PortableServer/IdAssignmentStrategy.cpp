// $Id$

#include "IdAssignmentStrategy.h"

ACE_RCSID (PortableServer,
           IdAssignmentStrategy,
           "$Id$")


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  namespace Portable_Server
  {
    void
    IdAssignmentStrategy::strategy_init (TAO_Root_POA * /*poa*/
					 ACE_ENV_ARG_DECL_NOT_USED)
    {
    }

    void
    IdAssignmentStrategy::strategy_cleanup(ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    {
    }

    char
    IdAssignmentStrategy::key_type_length (void) const
    {
      return sizeof (char);
    }

    void
    IdAssignmentStrategy::create_key (
      CORBA::Octet *buffer,
      CORBA::ULong& starting_at)
    {
      // Copy the system id byte.
      buffer[starting_at] = (CORBA::Octet) this->id_assignment_key_type ();
      starting_at += this->key_type_length ();
    }

  }
}

TAO_END_VERSIONED_NAMESPACE_DECL
