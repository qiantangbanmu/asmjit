// [AsmJit]
// Complete x86/x64 JIT and Remote Assembler for C++.
//
// [License]
// Zlib - See LICENSE.md file in the package.

// [Export]
#define ASMJIT_EXPORTS

// [Dependencies]
#include "../core/arch.h"
#include "../core/func.h"
#include "../core/type.h"

#ifdef ASMJIT_BUILD_X86
  #include "../x86/x86callconv_p.h"
#endif

#ifdef ASMJIT_BUILD_ARM
  #include "../arm/armcallconv_p.h"
#endif

ASMJIT_BEGIN_NAMESPACE

// ============================================================================
// [asmjit::CallConv - Init / Reset]
// ============================================================================

ASMJIT_FAVOR_SIZE Error CallConv::init(uint32_t ccId) noexcept {
  reset();

  #ifdef ASMJIT_BUILD_X86
  if (CallConv::isX86Family(ccId))
    return X86CallConvInternal::init(*this, ccId);
  #endif

  #ifdef ASMJIT_BUILD_ARM
  if (CallConv::isArmFamily(ccId))
    return ArmCallConvInternal::init(*this, ccId);
  #endif

  return DebugUtils::errored(kErrorInvalidArgument);
}

ASMJIT_END_NAMESPACE
