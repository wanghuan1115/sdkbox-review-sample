
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        /////////////////////////////
        // 2. add a menu item with "X" image, which is clicked to quit the program
        //    you may modify it.
        // ask the window size
        var size = cc.winSize;

        /////////////////////////////
        // 3. add your codes below...
        // add a label shows "Hello World"
        // create and initialize a label
        var helloLabel = new cc.LabelTTF("Hello World", "Arial", 38);
        // position the label on the center of the screen
        helloLabel.x = size.width / 2;
        helloLabel.y = size.height / 2 + 200;
        // add the label as a child to this layer
        this.addChild(helloLabel, 5);

        cc.log("111");
        var rateLabel = new cc.LabelTTF("Rate The App", "Arial", 18);
        var increaseLabel = new cc.LabelTTF("Increate User Event", "Arial", 18);

        var menuRate = new cc.MenuItemLabel(rateLabel, this.onRateClicked, this);
        menuRate.x = 200;
        menuRate.y = 200;
        var menuIncrease = new cc.MenuItemLabel(increaseLabel, this.onIncreaseClicked, this);
        menuIncrease.x = 200;
        menuIncrease.y = 150;

        var menu = new cc.Menu(menuRate, menuIncrease);
        menu.x = 0;
        menu.y = 0;
        this.addChild(menu, 5);

        // add "HelloWorld" splash screen"
        this.sprite = new cc.Sprite(res.HelloWorld_png);
        this.sprite.attr({
            x: size.width / 2,
            y: size.height / 2
        });
        // this.addChild(this.sprite, 0);

        var plugin = sdkbox.PluginReview
        plugin.setListener({
          didDisplayAlert: function(data) {cc.log("didDisplayAlert")},
          didDeclineToRate: function(data) { cc.log("didDeclineToRate") },
          didToRate: function(data) { cc.log("didToRate") },
          didToRemindLater: function(data) { cc.log("didToRemindLater") }
        })
        plugin.init()

        return true;
    },
    onRateClicked:function() {
        var plugin = sdkbox.PluginReview
        plugin.forceToShowPrompt()
    },
    onIncreaseClicked:function() {
        var plugin = sdkbox.PluginReview
        plugin.userDidSignificantEvent()
    }

});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

