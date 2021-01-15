#include "hermes.h"
#include "data_placement_engine.h"

namespace hermes {

int PlaceInHierarchy(SharedMemoryContext *context, RpcContext *rpc,
                     SwapBlob swap_blob, const std::string &name) {
  int result = 0;
  std::vector<PlacementSchema> schemas;
  std::vector<size_t> sizes(1, swap_blob.size);
  api::Context ctx;
  Status ret = CalculatePlacement(context, rpc, sizes, schemas, ctx);

  if (ret == 0) {
    std::vector<u8> blob_mem(swap_blob.size);
    Blob blob = {};
    blob.data = blob_mem.data();
    blob.size = blob_mem.size();
    size_t bytes_read = ReadFromSwap(context, blob, swap_blob);
    if (bytes_read != swap_blob.size) {
      // TODO(chogan): @errorhandling
      result = 1;
    }

    ret = PlaceBlob(context, rpc, schemas[0], blob, name.c_str(),
                    swap_blob.bucket_id, 0, true);
  } else {
    // TODO(chogan): @errorhandling
    result = 1;
  }

  return result;
}

int MoveToTarget(SharedMemoryContext *context, RpcContext *rpc, BlobID blob_id,
                 TargetID dest) {
  (void)(context);
  (void)(rpc);
  (void)(blob_id);
  (void)(dest);
// TODO(chogan): Move blob from current location to Target dest
  HERMES_NOT_IMPLEMENTED_YET;
  int result = 0;
  return result;
}

}  // namespace hermes
