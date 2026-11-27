// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cpObjCollision.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cBitCtrl.h"
#include "cGuardInfo.h"
#include "cHitInfoAfter.h"
#include "cHitNode.h"
#include "cObjHitCache.h"
#include "cOcdDamageInfo.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "nObjCollision.h"
#include "rAttackParam.h"
#include "sAIPawnNotice.h"
#include "../../XFramework/sCollision.h"
#include "sObjCollision.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

template const MtDTI& cpObjCollisionInst<64, 8>::getDTI() const;

