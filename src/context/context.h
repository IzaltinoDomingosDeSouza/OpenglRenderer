#pragma once

#include "app_ctx.h"
#include "input_ctx.h"
#include "renderer/renderer.h"

struct Context
{
    AppCtx * application;
    InputCtx * input;
    Renderer * renderer;
};