cmake_minimum_required(VERSION 3.22)
project(iphoneAudio VERSION 0.0.1)

include(FetchContent)

FetchContent_Declare(
	JUCE
	GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
	GIT_TAG 8.0.12
)

FetchContent_MakeAvailable(JUCE)

if(IOS)
    set(iphoneAudio_FORMATS Standalone)
else()
    set(iphoneAudio_FORMATS AU VST3 Standalone)
endif()


juce_add_plugin(iphoneAudio
	COMPANY_NAME                "Luke Amos"
    BUNDLE_ID                   com.lukeamos.iphoneaudio
    IS_SYNTH                    TRUE 
    NEEDS_MIDI_INPUT            TRUE
    NEEDS_MIDI_OUTPUT           FALSE
    IS_MIDI_EFFECT              FALSE
    COPY_PLUGIN_AFTER_BUILD     TRUE
    PLUGIN_MANUFACTURER_CODE    Lkam
    PLUGIN_CODE                 ipau
    FORMATS                      ${iphoneAudio_FORMATS}
    PRODUCT_NAME                "iPhone Audio"
)

if(IOS)
    set_target_properties(iphoneAudio_Standalone PROPERTIES
        XCODE_ATTRIBUTE_CODE_SIGN_STYLE "Automatic"
        XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "Apple Development"
        XCODE_ATTRIBUTE_ARCHS "arm64"
        XCODE_ATTRIBUTE_VALID_ARCHS "arm64"
        XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY "1"
        
        # Cleaned XML string without hidden formatting tabs inside tags
        CUSTOM_PLIST "<plist><dict><key>UIBackgroundModes</key><array><string>audio</string></array><key>NSMicrophoneUsageDescription</key><string>Audio playback authorization.</string></dict></plist>"
    )
    
    # Overrides iOS ambient muting defaults
    target_compile_definitions(iphoneAudio PRIVATE JUCE_AUDIO_ALLOWS_ANY_OS_AUDIO_RULES=1)
endif()



juce_generate_juce_header(iphoneAudio)

target_sources(iphoneAudio
    PRIVATE
	Source/PluginProcessor.cpp
    Source/PluginProcessor.h
    Source/PluginEditor.cpp
    Source/PluginEditor.h
    Source/UI/DraggableComponent.h
    Source/UI/DraggableComponent.cpp
    Source/Synthesiser/SynthVoice.h
    Source/Synthesiser/SynthVoice.cpp
)




source_group("Source" FILES
    Source/PluginProcessor.cpp
    Source/PluginProcessor.h
    Source/PluginEditor.cpp
    Source/PluginEditor.h
)

source_group("Source\\UI" FILES

    Source/UI/DraggableComponent.h
    Source/UI/DraggableComponent.cpp

)

source_group("Source\\Synthesiser" FILES

    Source/Synthesiser/SynthVoice.h
    Source/Synthesiser/SynthVoice.cpp

)

target_compile_definitions(iphoneAudio
    PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(iphoneAudio
    PRIVATE
        juce::juce_audio_utils
	juce::juce_dsp
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)
