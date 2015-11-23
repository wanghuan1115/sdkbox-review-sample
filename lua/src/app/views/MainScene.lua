
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    -- add background image
    -- display.newSprite("HelloWorld.png")
    --     :move(display.center)
    --     :addTo(self)

    local textLabel = cc.Label:createWithSystemFont("The rate prompt will show, when 3rd launch", "Arial", 20)
        :move(display.cx, display.cy)
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
            if "onDisplayAlert" == event then
                print("didDisplayAlert")
            elseif "onDeclineToRate" == event then
                print("didDeclineToRate")
            elseif "onRate" == event then
                print("didToRate")
            elseif "onRemindLater" == event then
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
        plugin:show(true)
    else
        print "not found plugin"
    end
end

return MainScene
