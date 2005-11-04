/* -*- C++ -*- */

//=============================================================================
/**
 *  @file PortableServer.h
 *
 *  $Id$
 *
 *  @author Carlos O'Ryan <coryan@uci.edu>
 */
//=============================================================================

#ifndef TAO_PORTABLESERVER_H
#define TAO_PORTABLESERVER_H

#include /**/ "ace/pre.h"

#include "portableserver_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Versioned_Namespace.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_PortableServer_Export TAO_POA_Initializer
{
public:
  /// Used to force the initialization of the ORB code.
  static int init (void);
};

static int
TAO_Requires_POA_Initializer = TAO_POA_Initializer::init ();

TAO_END_VERSIONED_NAMESPACE_DECL

#define TAO_PORTABLESERVER_SAFE_INCLUDE
#include "PortableServerC.h"
#undef TAO_PORTABLESERVER_SAFE_INCLUDE
#include "POAManagerC.h"
#include "PS_CurrentC.h"
#include "PortableServer_Functions.h"
#include "PortableServer_WFunctions.h"
#include "PS_ForwardA.h"
#include "IdUniquenessPolicyA.h"
#include "ImplicitActivationPolicyA.h"
#include "RequestProcessingPolicyA.h"
#include "ServantRetentionPolicyA.h"
#include "ThreadPolicyA.h"
#include "IdAssignmentPolicyA.h"
#include "LifespanPolicyA.h"

#include /**/ "ace/post.h"

#endif /* TAO_PORTABLESERVER_H */
