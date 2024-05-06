/*
  ==============================================================================

    TT_PatchNames.h
    Created: 10 Apr 2024 12:41:45pm
    Author:  Matt Twitchen

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

namespace PatchNames
{
    static const std::vector<juce::String> bright = {
        "Radiant", "Brilliant", "Luminous", "Gleaming", "Sunny",
        "Vivid", "Shimmering", "Sparkling", "Dazzling", "Glowing",
        "Beaming", "Incandescent", "Scintillating", "Effulgent", "Resplendent",
        "Sunlit", "Glimmering", "Luminescent", "Blazing", "Illuminated",
        "Glisten", "Flash", "Shine", "Twinkle", "Brilliance",
        "Luster", "Glitter", "Splendor", "Twinkling", "Beacon",
        "Radiance", "Golden", "Shining", "Dazzling Ray", "Sparkle",
        "Gleaming Star", "Radiant Glow", "Glow", "Resplendent", "Luminosity"
    };

    static const std::vector<juce::String> dark = {
        "Shadowy", "Murky", "Gloomy", "Dim", "Obscure",
        "Dusky", "Somber", "Dreary", "Mysterious", "Sullen",
        "Tenebrous", "Eclipsed", "Opaque", "Blackened", "Shaded",
        "Stygian", "Funereal", "Shrouded", "Dimmed", "Pitch-black",
        "Shadow", "Umbral", "Enshrouded", "Cimmerian", "Nocturnal",
        "Grim", "Eerie", "Obsidian", "Nightfall", "Tenebrific",
        "Gloom", "Cimmerian", "Stygian", "Shroud", "Murk",
        "Shadiness", "Shaded", "Obscurity", "Blackness", "Dusk"
    };

    static const std::vector<juce::String> resonant = {
        "Rich", "Vibrant", "Sonorous", "Booming", "Reverberant",
        "Full-bodied", "Echoing", "Deep", "Mellifluous", "Harmonic",
        "Robust", "Pulsating", "Resounding", "Thrilling", "Powerful",
        "Penetrating", "Vociferous", "Buoyant", "Palpitating", "Thriving",
        "Drone", "Vibration", "Boom", "Thrum", "Pulse",
        "Rumble", "Chime", "Vibrato", "Thrill", "Power",
        "Bass", "Echoic", "Resonating", "Thriving Resonance", "Thriving Sound",
        "Resounding Impact", "Humming", "Ring", "Pulsation", "Vociferation"
    };

    static const std::vector<juce::String> soft = {
        "Gentle", "Mellow", "Tender", "Delicate", "Soothing",
        "Subtle", "Hushed", "Tranquil", "Mild", "Serene",
        "Calm", "Placid", "Silken", "Velvety", "Light",
        "Ethereal", "Airy", "Peaceful", "Balmy", "Soporific",
        "Whisper", "Feather", "Lullaby", "Pillow", "Breeze",
        "Touch", "Dream", "Calmness", "Mildness", "Serenity",
        "Ethereality", "Airiness", "Tranquility", "Soothingness", "Peacefulness",
        "Placidity", "Delicacy", "Gentleness", "Silkenness", "Velvetiness"
    };

    static const std::vector<juce::String> pluck = {
        "String", "Pick", "Snap", "Strum", "Fret",
        "Chord", "Stroke", "Note", "Tap", "Riff",
        "Pull", "Slide", "Harp", "Pinch", "Pluck",
        "Twang", "Thrust", "Quiver", "Strike", "Tug",
        "String", "Pick", "Snap", "Strum", "Fret",
        "Chord", "Stroke", "Note", "Tap", "Riff",
        "Pull", "Slide", "Harp", "Pinch", "Pluck",
        "Twang", "Thrust", "Quiver", "Strike", "Tug"
    };

    static const std::vector<juce::String> longRelease = {
        "Tail", "Echo", "Decay", "Reverb", "Sustain",
        "Fade", "Ring", "Drift", "Drone", "Lingering",
        "Resonance", "Hold", "Hum", "Extension", "Echoing",
        "Residue", "Continuation", "Duration", "Suspension", "Reverberation",
        "Tail", "Echo", "Decay", "Reverb", "Sustain",
        "Fade", "Ring", "Drift", "Lingering", "Hold",
        "Hum", "Extension", "Residue", "Continuation", "Duration",
        "Suspension", "Reverberation", "Remnant", "Residual", "Persistence"
    };

    static const std::vector<juce::String> swell = {
        "Wave", "Surge", "Crest", "Build-up", "Expansion",
        "Growth", "Increase", "Rise", "Peak", "Intensification",
        "Augmentation", "Influx", "Pulsation", "Thrust", "Elevation",
        "Flood", "Onset", "Mount", "Upturn", "Updraft",
        "Wave", "Surge", "Crest", "Build-up", "Expansion",
        "Growth", "Increase", "Rise", "Peak", "Intensification",
        "Augmentation", "Influx", "Elevation", "Flood", "Onset",
        "Mount", "Upturn", "Updraft", "Uprise", "Heightening"
    };

    static const std::vector<juce::String> shortV = {
        "Burst", "Snap", "Stab", "Flash", "Tap",
        "Jolt", "Blink", "Flick", "Dart", "Zip",
        "Quickie", "Dash", "Spurt", "Whiff", "Sip",
        "Snip", "Jerk", "Skip", "Bump", "Swoosh",
        "Burst", "Stab", "Flash", "Tap", "Jolt",
        "Blink", "Flick", "Dart", "Zip", "Quickie",
        "Dash", "Spurt", "Whiff", "Sip", "Snip",
        "Jerk", "Skip", "Bump", "Swoosh", "Snap"
    };
}
