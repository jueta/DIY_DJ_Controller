function DJCDIY() {}

DJCDIY.lastPlaylistScrollTime = 0;

DJCDIY.wheelTurn = function (channel, control, value, status, group) {
    var newValue=(value-64);
    engine.setValue(group, "jog", newValue)   
    engine.scratchTick(1,newValue);
}

DJCDIY.playlistScrollLibrary = function (channel, control, value, status, group) {
    var now = new Date().getTime();
    var delta = value > 64 ? 1 : value < 64 ? -1 : 0;

    if (now - DJCDIY.lastPlaylistScrollTime >= 15 && delta !== 0) {
        DJCDIY.lastPlaylistScrollTime = now;
        engine.setValue("[Playlist]", "SelectTrackKnob", delta);
    }
}

DJCDIY.playlistScrollNoop = function (channel, control, value, status, group) {
}

DJCDIY.playlistScroll = DJCDIY.playlistScrollLibrary;
