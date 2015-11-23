
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

        var textLabel = new cc.LabelTTF("The rate prompt will show, when 3rd launch", "Arial", 20);
        textLabel.x = size.width/2
        textLabel.y = size.height/2
        this.addChild(textLabel, 5)

        var plugin = sdkbox.PluginReview
        plugin.setListener({
          onDisplayAlert: function(data) {cc.log("didDisplayAlert")},
          onDeclineToRate: function(data) { cc.log("didDeclineToRate") },
          onRate: function(data) { cc.log("didToRate") },
          onRemindLater: function(data) { cc.log("didToRemindLater") }
        })
        plugin.init()

        return true;
    }

});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

