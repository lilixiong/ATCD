// $Id$
// ==========================================================================
//
// = LIBRARY
//   Orbsvcs
//
// = FILENAME
//   Notify_Resource_Manager.h
//
// = DESCRIPTION
//   Resource Manager for the Notify Service implementation.
//
// = AUTHOR
//    Pradeep Gore <pradeep@cs.wustl.edu>
//
// ==========================================================================
#ifndef TAO_NOTIFY_RESOURCE_MANAGER
#define TAO_NOTIFY_RESOURCE_MANAGER
#include "ace/pre.h"

#include "tao/POA.h"
#include "orbsvcs/CosNotifyChannelAdminS.h"
#include "Notify_ID_Pool_T.h"
#include "notify_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class TAO_Notify_EventChannelFactory_i;
class TAO_Notify_EventChannel_i;
class TAO_Notify_FilterFactory_i;
class TAO_Notify_ConsumerAdmin_i;
class TAO_Notify_SupplierAdmin_i;
class TAO_Notify_StructuredProxyPushSupplier_i;
class TAO_Notify_SequenceProxyPushSupplier_i;
class TAO_Notify_ProxyPushSupplier_i;
class TAO_Notify_StructuredProxyPushConsumer_i;
class TAO_Notify_SequenceProxyPushConsumer_i;
class TAO_Notify_ProxyPushConsumer_i;
class TAO_Notify_Event_Manager;

class TAO_Notify_Export TAO_Notify_Resource_Manager
{
  // = TITLE
  //   Notify_Resource_Factory
  //
  // = DESCRIPTION
  //   This is class to control all the resources needed by all the other
  //   classes.
  //
  //   @@ Pradeep: this is a class a factory? Or is it a manager for
  //   resource created by a factory?  The interfaces should be quite
  //   different, and it is hard to turn a manager into a Service
  //   Object (but factories are much easier).  If you check the
  //   design of the RTEC and the new CosEC you will notice that the
  //   Event_Channel class plays the manager role and the factory is a
  //   separate entity.  Your idea of separating the manager from the
  //   Event_Channel is probably the "Right Thing" but you should also
  //   decouple the factory and manager roles.
  //
  //   Later: The class is also a Service Object that will configure the
  //   service on startup.

 public:

  TAO_Notify_Resource_Manager (PortableServer::POA_ptr default_POA);
  // Constructor.

  ~TAO_Notify_Resource_Manager ();
  // Destructor.

  // = Factory method
  static TAO_Notify_Resource_Manager* create (PortableServer::POA_ptr default_POA, CORBA::Environment &ACE_TRY_ENV);
  // Factory method to create the Resource Factory Manager.
  // @@ Pradeep: how is that possible?  I still have to know the class
  // to create it, right?
  // This allows other specializations of the Resource Factory to be created
  // via a common interface.

  // = Accessors
  PortableServer::POA_ptr get_default_POA (void);
  // Returns the default POA.

  CosNotifyFilter::FilterFactory_ptr get_default_filter_factory (void);
  // Returns the default filter factory.

  // = Creation methods
  TAO_Notify_EventChannel_i* create_event_channel (TAO_Notify_EventChannelFactory_i* parent, CORBA::Environment &ACE_TRY_ENV);
  // Create an Event Channel.

  TAO_Notify_ConsumerAdmin_i* create_consumer_admin (TAO_Notify_EventChannel_i* channel, CORBA::Environment &ACE_TRY_ENV);
  // Create a Consumer Admin.

  TAO_Notify_SupplierAdmin_i* create_supplier_admin (TAO_Notify_EventChannel_i* channel, CORBA::Environment &ACE_TRY_ENV);
  // Create a Supplier Admin.

  TAO_Notify_FilterFactory_i* create_filter_factory (CORBA::Environment &ACE_TRY_ENV);
  // Create the Filter Factory.

  TAO_Notify_Event_Manager* create_event_manager (TAO_Notify_EventChannel_i* channel, CORBA::Environment &ACE_TRY_ENV);
  // Create an event manager.

  TAO_Notify_StructuredProxyPushSupplier_i* create_struct_proxy_pushsupplier (TAO_Notify_ConsumerAdmin_i* parent, CORBA::Environment &ACE_TRY_ENV);
  // Create a Structured ProxyPushSupplier.

  TAO_Notify_SequenceProxyPushSupplier_i* create_seq_proxy_pushsupplier (TAO_Notify_ConsumerAdmin_i* parent, CORBA::Environment &ACE_TRY_ENV);
  // Create a Sequence ProxyPushSupplier.

  TAO_Notify_ProxyPushSupplier_i* create_proxy_pushsupplier (TAO_Notify_ConsumerAdmin_i* parent, CORBA::Environment &ACE_TRY_ENV);
  // Create a ProxyPushSupplier.

  TAO_Notify_StructuredProxyPushConsumer_i* create_struct_proxy_pushconsumer (TAO_Notify_SupplierAdmin_i* parent, CORBA::Environment &ACE_TRY_ENV);
  // Create a Structured ProxyPushConsumer.

  TAO_Notify_SequenceProxyPushConsumer_i* create_seq_proxy_pushconsumer (TAO_Notify_SupplierAdmin_i* parent, CORBA::Environment &ACE_TRY_ENV);
  // Create a Sequence ProxyPushConsumer.

  TAO_Notify_ProxyPushConsumer_i* create_proxy_pushconsumer (TAO_Notify_SupplierAdmin_i* parent, CORBA::Environment &ACE_TRY_ENV);
  // Create a ProxyPushConsumer.

  PortableServer::POA_ptr create_event_channel_POA (PortableServer::POA_ptr parent_poa, CORBA::Environment &ACE_TRY_ENV);
  // Create the POA to activate Event Channels in.

  PortableServer::POA_ptr create_supplier_admin_POA (PortableServer::POA_ptr parent_poa, CORBA::Long new_poa_id, CORBA::Environment &ACE_TRY_ENV);
  // Create the POA to activate SA's in.

  PortableServer::POA_ptr create_consumer_admin_POA (PortableServer::POA_ptr parent_poa, CORBA::Long new_poa_id, CORBA::Environment &ACE_TRY_ENV);
  // Create the POA to activate CA's in.

  PortableServer::POA_ptr create_proxy_pushconsumer_POA (PortableServer::POA_ptr parent_poa, CORBA::Long new_poa_id, CORBA::Environment &ACE_TRY_ENV);
  // Create the POA to activate proxy push consumers in.

  PortableServer::POA_ptr create_proxy_pushsupplier_POA (PortableServer::POA_ptr parent_poa, CORBA::Long new_poa_id, CORBA::Environment &ACE_TRY_ENV);
  // Create the POA to activate proxy push suppliers in.

  // = Object activation and POA methods
  CORBA::Object_ptr activate_object_with_id (CORBA::Long id, PortableServer::POA_ptr poa,PortableServer::Servant servant, CORBA::Environment &ACE_TRY_ENV);
  // Converts <id> to an ObjectId and registers with the POA <poa>.

  CORBA::Object_ptr activate_object (PortableServer::POA_ptr poa,PortableServer::Servant servant, CORBA::Environment &ACE_TRY_ENV);
  // Registers with the POA <poa>.

  CORBA::Object_ptr servant_to_reference (PortableServer::POA_ptr poa,PortableServer::Servant servant, CORBA::Environment &ACE_TRY_ENV);
  // Registers with the POA <poa>.

  CORBA::Object_ptr id_to_reference (CORBA::Long id, PortableServer::POA_ptr poa, CORBA::Environment &ACE_TRY_ENV);
  // Look for the Object with id <id> in <poa>.

  void destroy_POA (PortableServer::POA_ptr poa, CORBA::Environment &ACE_TRY_ENV = TAO_default_environment ());
  // Destroy the <poa>

  void deactivate_object (CORBA::Object_ptr obj, PortableServer::POA_ptr poa, CORBA::Environment &ACE_TRY_ENV = TAO_default_environment ());
  // Deactivate the object.

  void deactivate_object (PortableServer::Servant servant, PortableServer::POA_ptr, CORBA::Environment &ACE_TRY_ENV = TAO_default_environment ());
  // Deactivate the object.

  // = Options
  CORBA::Boolean default_subscription_enabled (void);
  // True if new born event listeners should be subscribed for all the events.

 protected:
  // = Helper methods
  void init_i (CORBA::Environment &ACE_TRY_ENV);
  // Initialize.

  PortableServer::ObjectId* long_to_ObjectId (const CORBA::Long id);
  // Converts a CORBA::Long to an ObjectId

  PortableServer::POA_ptr create_generic_childPOA_i (const char* child_poa_name, PortableServer::POA_ptr parent_poa, CORBA::Environment &ACE_TRY_ENV);
  // Create the POA with the most generic policies required of our POA's.

  CosNotifyFilter::FilterFactory_ptr create_default_filter_factory_i (CORBA::Environment& ACE_TRY_ENV);
  // Create the filter factory used by all ECs.

  // = Data Members
  PortableServer::POA_var default_POA_;
  // The default POA to use.

  CosNotifyFilter::FilterFactory_var default_filter_factory_;
  // The default filter factory.
  // We create and own this.
};

#include "ace/post.h"
#endif /* TAO_NOTIFY_RESOURCE_MANAGER */
