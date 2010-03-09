// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.6
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 *       http://doc.ece.uci.edu/
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// .\be\be_codegen.cpp:1217

#ifndef CIAO_STOCKBROKER_EXEC_H_
#define CIAO_STOCKBROKER_EXEC_H_


#include "StockBrokerEC.h"

#include <set>
#include <string>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "StockBroker_exec_export.h"
#include "tao/LocalObject.h"


namespace CIAO_Stock_StockBroker_Impl
{
  class STOCKBROKER_EXEC_Export StockBroker_exec_i
    : public virtual StockBroker_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    StockBroker_exec_i (void);
    virtual ~StockBroker_exec_i (void);
    
    //@{
    /** Supported operations and attributes. */
    
    
    // TAO_IDL - Generated from
    // c:\middleware\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:42
    
    virtual void
    stock_subscribe (
      const char * stock_name);
    
    // TAO_IDL - Generated from
    // c:\middleware\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ch.cpp:42
    
    virtual void
    stock_unsubscribe (
      const char * stock_name);
    //@}
    
    //@{
    /** Component attributes and port operations. */
    
    
    virtual void
    push_notify_in (
      ::Stock::StockName * ev);
    //@}
    
    //@{
    /** Operations from Components::SessionComponent. */
    
    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);
    
    virtual void configuration_complete (void);
    
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}
    
  
  private:
    ::Stock::CCM_StockBroker_Context_var context_;
    std::set<std::string> subscribed_stock_list_;
  };
  
  extern "C" STOCKBROKER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Stock_StockBroker_Impl (void);
}

namespace CIAO_Stock_StockBroker_Impl
{
  class STOCKBROKER_EXEC_Export StockBrokerHome_exec_i
    : public virtual StockBrokerHome_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    StockBrokerHome_exec_i (void);
    
    virtual ~StockBrokerHome_exec_i (void);
    
    // All operations and attributes.
    
    // Factory operations.
    
    // Finder operations.
    
    // Implicit operations.
    
    virtual ::Components::EnterpriseComponent_ptr
    create (void);
  };
  
  extern "C" STOCKBROKER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Stock_StockBrokerHome_Impl (void);
}

#endif /* ifndef */

