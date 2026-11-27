// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rRenderTargetTexture.h"
#include "../MT/MtDTI.h"
#include "../MT/MtFilePath.h"
#include "../MT/MtFunctionReplacement.h"
#include "../MT/MtObject.h"
#include "nDrawTexture.h"
#include "rTexture.h"
#include "sRender.h"
#include "../MT/MtStream.h"
#include <cstring>

#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rRenderTargetTexture::getDTI() const {
    return rRenderTargetTexture::DTI;
}

void rRenderTargetTexture::clear() {
    this->rTexture::clear();
}

__attribute__((weak)) bool rRenderTargetTexture::load(MtStream& in) {
    rTexture::HEADER hdr;
    in.read(&hdr, 16);
    if (hdr.magic != 0x585452u) {
        return false;
    }
    if (hdr.version != 0x9eu || !hdr.render_target) {
        return false;
    }
    if (hdr.auto_resize) {
        f32 wratio = (f32)(s32)hdr.width * 0.000244140625f;
        f32 hratio = (f32)(s32)hdr.height * 0.000244140625f;
        hdr.width = (u32)(s32)(wratio * (f32)sRender::getInstance()->mScreenSize.w);
        hdr.height = (u32)(s32)(hratio * (f32)sRender::getInstance()->mScreenSize.h);
        mOrgInvWidth = 1.0f / (f32)(s32)hdr.width;
        mOrgInvHeight = 1.0f / (f32)(s32)hdr.height;
        mOrgWidth = hdr.width;
        mOrgHeight = hdr.height;
        mOrgDepth = 0;
    } else {
        mOrgInvWidth = 1.0f / (f32)(s32)hdr.width;
        mOrgInvHeight = 1.0f / (f32)(s32)hdr.height;
        mOrgWidth = hdr.width;
        mOrgHeight = hdr.height;
        mOrgDepth = 0;
        nDraw::Texture::calcMipLevelCount(hdr.width > hdr.height ? hdr.width : hdr.height);
        const u32 w = sRender::getInstance()->mScreenSize.w;
        const u32 h = sRender::getInstance()->mScreenSize.h;
        while (hdr.width > w || hdr.height > h) {
            hdr.width = hdr.width >> 1;
            hdr.height = hdr.height >> 1;
            hdr.level_count = hdr.level_count - 1;
        }
    }
    return createRenderTarget(hdr.type, hdr.width, hdr.height, hdr.level_count, (nDraw::FORMAT_TYPE)hdr.format, hdr.auto_resize);
}

__attribute__((weak)) bool rRenderTargetTexture::save(MtStream& out) {
    nDraw::Texture* phandle = mpTexture;
    if (phandle == nullptr) {
        return false;
    }
    rTexture::HEADER hdr = {};
    hdr.magic = 0x585452u;
    hdr.version = 0x9eu;
    hdr.type = phandle->mTextureType;
    hdr.auto_resize = (phandle->mMiscFlags >> 1) & 1u;
    hdr.render_target = phandle->mUsageType == (nDraw::USAGE_TYPE)2;
    if (hdr.auto_resize) {
        sRender* render = sRender::getInstance();
        hdr.width = (u32)(s32)((f32)mOrgWidth / (f32)render->mScreenSize.w * 4096.0f);
        hdr.height = (u32)(s32)((f32)mOrgHeight / (f32)render->mScreenSize.h * 4096.0f);
    } else {
        hdr.width = mOrgWidth;
        hdr.height = mOrgHeight;
    }
    hdr.depth = mOrgDepth;
    hdr.level_count = phandle->mLevelCount;
    hdr.array_count = phandle->mArrayCount;
    hdr.format = phandle->mFormatType;
    out.write(&hdr, 16);
    return true;
}

MT_CTSTR rRenderTargetTexture::getExt() const {
    return "rtex";
}

void rRenderTargetTexture::createProperty(MtPropertyList& s) {
    this->rTexture::createProperty(s);
}

__attribute__((weak)) bool rRenderTargetTexture::createRenderTarget(u32 type, u32 width, u32 height, u32 level_count, nDraw::FORMAT_TYPE format, bool auto_resize) {
    nDraw::Texture* ptex = nullptr;
    if (type == 6) {
        ptex = new (16u) nDraw::Texture(width, width, level_count, 6u, format, (nDraw::USAGE_TYPE)2, 0x408008u, nullptr, 0u, nullptr, (nDraw::TEXMEMORY_TYPE)16);
    } else if (type == 2) {
        u32 misc = (u32)auto_resize * 2u;
        MtFilePath path(mPath);
        MT_CHAR cmd[1024];
        strcpy(cmd, path.getFileTitle());
        MtReplaceFunc::detail::_strupr(cmd);
        for (MT_STR token = strtok(cmd, "_-0123456789"); token != nullptr; token = strtok(nullptr, "_-0123456789")) {
            if (strcmp(token, "NM") == 0 || strcmp(token, "PM") == 0 || strcmp(token, "DM") == 0) {
                misc |= 0xb0f000u;
                format = (nDraw::FORMAT_TYPE)0x27;
                break;
            }
        }
        ptex = new (16u) nDraw::Texture(width, height, level_count, 1u, format, (nDraw::USAGE_TYPE)2, misc, nullptr, 0u, nullptr, (nDraw::TEXMEMORY_TYPE)16);
    } else if (type == 1) {
        ptex = new (16u) nDraw::Texture(width, height, level_count, 1u, format, (nDraw::USAGE_TYPE)2, (u32)auto_resize * 2u, nullptr, 0u, nullptr, (nDraw::TEXMEMORY_TYPE)16);
    }
    setHandle(ptex);
    return ptex != nullptr;
}

rRenderTargetTexture::~rRenderTargetTexture() {
    this->rTexture::clear();
}

inline rRenderTargetTexture::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rRenderTargetTexture::MyDTI rRenderTargetTexture::DTI("rRenderTargetTexture", &::rTexture::DTI, 264ul, 0u, 0u);

MtObject* rRenderTargetTexture::MyDTI::newInstance() const {
    return new (16u) rRenderTargetTexture;
}

