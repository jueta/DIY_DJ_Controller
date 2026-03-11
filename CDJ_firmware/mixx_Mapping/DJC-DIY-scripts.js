function DJCDIY() {}

DJCDIY.wheelTurn = function (channel, control, value, status, group) {
    var newValue=(value-64);
    engine.setValue(group, "jog", newValue)   
    engine.scratchTick(1,newValue);
}

DJCDIY.loadDeck2 = function (channel, control, value, status, group) {
    if (value > 0) {
        engine.setValue("[Playlist]", "LoadSelectedIntoSecondDeck", 1);
    }
}

DJCDIY.playlistScroll = function (channel, control, value, status, group) {
    var direction = (value > 64) ? 1 : -1;
    engine.setValue("[Playlist]", "MoveSelection", direction);
}