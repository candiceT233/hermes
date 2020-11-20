#include "mpi.h"

#include "buffer_pool.h"
#include "buffer_pool_internal.h"
#include "metadata_management.h"
#include "rpc.h"

#include "debug_state.cc"
#include "memory_management.cc"
#include "config_parser.cc"
#include "utils.cc"

#if defined(HERMES_COMMUNICATION_MPI)
#include "communication_mpi.cc"
#elif defined(HERMES_COMMUNICATION_ZMQ)
#include "communication_zmq.cc"
#else
#error "Communication implementation required " \
  "(e.g., -DHERMES_COMMUNICATION_MPI)."
#endif

#if defined(HERMES_RPC_THALLIUM)
#include "rpc_thallium.cc"
#else
#error "RPC implementation required (e.g., -DHERMES_RPC_THALLIUM)."
#endif

#include "metadata_management.cc"
#include "buffer_organizer.cc"

#if defined(HERMES_MDM_STORAGE_STBDS)
#include "metadata_storage_stb_ds.cc"
#else
#error "Metadata storage implementation required" \
  "(e.g., -DHERMES_MDM_STORAGE_STBDS)."
#endif

#include "hermes.cc"
#include "bucket.cc"
#include "vbucket.cc"
#include "data_placement_engine.cc"
#include "buffer_pool.cc"