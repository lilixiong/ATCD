
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl NoOp_Configurator
// ------------------------------
#ifndef NOOP_CONFIGURATOR_EXPORT_H
#define NOOP_CONFIGURATOR_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (NOOP_CONFIGURATOR_HAS_DLL)
#  define NOOP_CONFIGURATOR_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && NOOP_CONFIGURATOR_HAS_DLL */

#if !defined (NOOP_CONFIGURATOR_HAS_DLL)
#  define NOOP_CONFIGURATOR_HAS_DLL 1
#endif /* ! NOOP_CONFIGURATOR_HAS_DLL */

#if defined (NOOP_CONFIGURATOR_HAS_DLL) && (NOOP_CONFIGURATOR_HAS_DLL == 1)
#  if defined (NOOP_CONFIGURATOR_BUILD_DLL)
#    define NoOp_Configurator_Export ACE_Proper_Export_Flag
#    define NOOP_CONFIGURATOR_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define NOOP_CONFIGURATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* NOOP_CONFIGURATOR_BUILD_DLL */
#    define NoOp_Configurator_Export ACE_Proper_Import_Flag
#    define NOOP_CONFIGURATOR_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define NOOP_CONFIGURATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* NOOP_CONFIGURATOR_BUILD_DLL */
#else /* NOOP_CONFIGURATOR_HAS_DLL == 1 */
#  define NoOp_Configurator_Export
#  define NOOP_CONFIGURATOR_SINGLETON_DECLARATION(T)
#  define NOOP_CONFIGURATOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* NOOP_CONFIGURATOR_HAS_DLL == 1 */

// Set NOOP_CONFIGURATOR_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (NOOP_CONFIGURATOR_NTRACE)
#  if (ACE_NTRACE == 1)
#    define NOOP_CONFIGURATOR_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define NOOP_CONFIGURATOR_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !NOOP_CONFIGURATOR_NTRACE */

#if (NOOP_CONFIGURATOR_NTRACE == 1)
#  define NOOP_CONFIGURATOR_TRACE(X)
#else /* (NOOP_CONFIGURATOR_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define NOOP_CONFIGURATOR_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (NOOP_CONFIGURATOR_NTRACE == 1) */

#endif /* NOOP_CONFIGURATOR_EXPORT_H */

// End of auto generated file.
