#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
struct MtFloat2;
struct MtFloat3;
struct MtFloat3x4;
class MtMatrix;
class MtVector4;

// Declarations
namespace nDraw { class ConstantTable; }

// Type aliases from DWARF
using u32 = unsigned int;
using SS_HANDLE = u32;
using SV_HANDLE = u32;
using f32 = float;
using s32 = int;

namespace nDraw {
    class ConstantTable
    {
    public:
        void setScalarF(SV_HANDLE handle, f32 v);
        void setScalarB(SV_HANDLE handle, bool v);
        void setScalarI(SV_HANDLE handle, s32 v);
        void setScalarArrayF(SV_HANDLE handle, const f32* v, u32 count);
        void setScalarArrayB(SV_HANDLE, const bool*, u32);
        void setScalarArrayI(SV_HANDLE, const s32*, u32);
        void setVectorF(SV_HANDLE handle, const f32* v);
        void setVectorB(SV_HANDLE, const bool*);
        void setVectorI(SV_HANDLE handle, const s32* v);
        void setVectorArrayF(SV_HANDLE handle, const f32* v, u32 count);
        void setVectorArrayB(SV_HANDLE, const bool*, u32);
        void setVectorArrayI(SV_HANDLE, const s32*, u32);
        void setMatrixF(SV_HANDLE handle, const f32* v);
        void setMatrixB(SV_HANDLE, const bool*);
        void setMatrixI(SV_HANDLE handle, const s32* v);
        void setMatrixArrayF(SV_HANDLE, const f32*, u32);
        void setMatrixArrayB(SV_HANDLE, const bool*, u32);
        void setMatrixArrayI(SV_HANDLE, const s32*, u32);
        void setStruct(SS_HANDLE handle, const void* pstruct);
        void setStructArray(SS_HANDLE handle, const void* pstruct, u32 count);
        f32 getScalarF(SV_HANDLE handle) const;
        u32 getScalarB(SV_HANDLE handle) const;
        s32 getScalarI(SV_HANDLE handle) const;
        f32 getScalarArrayF(SV_HANDLE, u32) const;
        u32 getScalarArrayB(SV_HANDLE, u32) const;
        s32 getScalarArrayI(SV_HANDLE, u32) const;
        const MtFloat2& getVector2F(SV_HANDLE handle) const;
        const MtFloat3& getVector3F(SV_HANDLE handle) const;
        const MtVector4& getVector4F(SV_HANDLE handle) const;
        const MtFloat2& getVectorArray2F(SV_HANDLE, u32) const;
        const MtFloat3& getVectorArray3F(SV_HANDLE, u32) const;
        const MtVector4& getVectorArray4F(SV_HANDLE handle, u32 index) const;
        const MtMatrix& getMatrix4x4F(SV_HANDLE handle) const;
        const MtFloat3x4& getMatrix3x4F(SV_HANDLE) const;
        const MtMatrix& getMatrixArray4x4F(SV_HANDLE, u32) const;
        const MtFloat3x4& getMatrixArray3x4F(SV_HANDLE, u32) const;
        const void* getStruct(SS_HANDLE) const;
        const void* getStructArray(SS_HANDLE handle, u32 index) const;
    private:
        u32 mBuffer[1];  // offset: 0x0
    };
}  // namespace nDraw
