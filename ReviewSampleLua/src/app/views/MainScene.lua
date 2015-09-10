
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    -- add background image
    -- display.newSprite("HelloWorld.png")
    --     :move(display.center)
    --     :addTo(self)

    -- add HelloWorld label
    cc.Label:createWithSystemFont("Review Lua Sample", "Arial", 40)
        :move(display.cx, display.cy + 200)
        :addTo(self)

    local labelRate = cc.Label:createWithSystemFont("Rate The App", "Arial", 20)
    local labelIncrease = cc.Label:createWithSystemFont("Increase The App", "Arial", 20)
    local btnRate = cc.MenuItemLabel:create(labelRate)
        :onClicked(function()
            print("onClicked")
            local plugin = sdkbox.PluginReview
            plugin:forceToShowPrompt()
        end)
        :move(display.cx, display.cy + 50)
    local btnIncreate = cc.MenuItemLabel:create(labelIncrease)
        :onClicked(function()
            print("onClicked")
            local plugin = sdkbox.PluginReview
            plugin:userDidSignificantEvent()
        end)
        :move(display.cx, display.cy)
    local menu = cc.Menu:create(btnRate, btnIncreate)
        :move(0, 0)
        :addTo(self, 1)

    self:initSDK()
end

function MainScene:initSDK()
    if not sdkbox then
        print "sdkbox is nil"
        return
    end

    print "Entry initSDK"

    if sdkbox.PluginReview then
        local plugin = sdkbox.PluginReview
        plugin:setListener(function(args)
            local event = args.event
            if "didDisplayAlert" == event then
                print("didDisplayAlert")
            elseif "didDeclineToRate" == event then
                print("didDeclineToRate")
            elseif "didToRate" == event then
                print("didToRate")
            elseif "didToRemindLater" == event then
                print("didToRemindLater")
            end
        end)
        plugin:init()
    else
        print "not found plugin"
    end
end

function MainScene:invokeFun()
    if not sdkbox then
        print "sdkbox is nil"
        return
    end

    print "Entry invokeFun"

    if sdkbox.PluginReview then
        local plugin = sdkbox.PluginReview
        plugin:forceToShowPrompt()
    else
        print "not found plugin"
    end
end

return MainScene
