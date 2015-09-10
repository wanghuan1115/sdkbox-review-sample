#include "PluginReviewLua.hpp"
#include "PluginReview/PluginReview.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"



int lua_PluginReviewLua_PluginReview_userDidSignificantEvent(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginReview:userDidSignificantEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_userDidSignificantEvent'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::userDidSignificantEvent(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:userDidSignificantEvent",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_userDidSignificantEvent'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_setCustomPromptTitle(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginReview:setCustomPromptTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_setCustomPromptTitle'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::setCustomPromptTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:setCustomPromptTitle",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_setCustomPromptTitle'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_setCustomPromptCancelButtonTitle(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginReview:setCustomPromptCancelButtonTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_setCustomPromptCancelButtonTitle'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::setCustomPromptCancelButtonTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:setCustomPromptCancelButtonTitle",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_setCustomPromptCancelButtonTitle'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_setCustomPromptMessage(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginReview:setCustomPromptMessage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_setCustomPromptMessage'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::setCustomPromptMessage(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:setCustomPromptMessage",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_setCustomPromptMessage'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginReview::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_setCustomPromptRateLaterButtonTitle(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginReview:setCustomPromptRateLaterButtonTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_setCustomPromptRateLaterButtonTitle'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::setCustomPromptRateLaterButtonTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:setCustomPromptRateLaterButtonTitle",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_setCustomPromptRateLaterButtonTitle'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_forceToShowPrompt(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_forceToShowPrompt'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::forceToShowPrompt();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "sdkbox.PluginReview:forceToShowPrompt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_forceToShowPrompt'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::forceToShowPrompt(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:forceToShowPrompt",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_forceToShowPrompt'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_setCustomPromptRateButtonTitle(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginReview:setCustomPromptRateButtonTitle");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_setCustomPromptRateButtonTitle'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::setCustomPromptRateButtonTitle(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:setCustomPromptRateButtonTitle",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_setCustomPromptRateButtonTitle'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginReviewLua_PluginReview_tryToShowPrompt(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginReview",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginReviewLua_PluginReview_tryToShowPrompt'", nullptr);
            return 0;
        }
        sdkbox::PluginReview::tryToShowPrompt();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginReview:tryToShowPrompt",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginReviewLua_PluginReview_tryToShowPrompt'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginReviewLua_PluginReview_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginReview)");
    return 0;
}

int lua_register_PluginReviewLua_PluginReview(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginReview");
    tolua_cclass(tolua_S,"PluginReview","sdkbox.PluginReview","",nullptr);

    tolua_beginmodule(tolua_S,"PluginReview");
        tolua_function(tolua_S,"userDidSignificantEvent", lua_PluginReviewLua_PluginReview_userDidSignificantEvent);
        tolua_function(tolua_S,"setCustomPromptTitle", lua_PluginReviewLua_PluginReview_setCustomPromptTitle);
        tolua_function(tolua_S,"setCustomPromptCancelButtonTitle", lua_PluginReviewLua_PluginReview_setCustomPromptCancelButtonTitle);
        tolua_function(tolua_S,"setCustomPromptMessage", lua_PluginReviewLua_PluginReview_setCustomPromptMessage);
        tolua_function(tolua_S,"init", lua_PluginReviewLua_PluginReview_init);
        tolua_function(tolua_S,"setCustomPromptRateLaterButtonTitle", lua_PluginReviewLua_PluginReview_setCustomPromptRateLaterButtonTitle);
        tolua_function(tolua_S,"forceToShowPrompt", lua_PluginReviewLua_PluginReview_forceToShowPrompt);
        tolua_function(tolua_S,"setCustomPromptRateButtonTitle", lua_PluginReviewLua_PluginReview_setCustomPromptRateButtonTitle);
        tolua_function(tolua_S,"tryToShowPrompt", lua_PluginReviewLua_PluginReview_tryToShowPrompt);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginReview).name();
    g_luaType[typeName] = "sdkbox.PluginReview";
    g_typeCast["PluginReview"] = "sdkbox.PluginReview";
    return 1;
}
TOLUA_API int register_all_PluginReviewLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginReviewLua_PluginReview(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

