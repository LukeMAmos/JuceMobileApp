
#include "PluginProcessor.h"
#include "PluginEditor.h"


iphoneAudioAudioProcessor::iphoneAudioAudioProcessor(){}
iphoneAudioAudioProcessor::~iphoneAudioAudioProcessor() {}

//==============================================================================
void iphoneAudioAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock) {
    
}
void iphoneAudioAudioProcessor::releaseResources() {
    
}

bool iphoneAudioAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const {
    
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}

void iphoneAudioAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiBuffer) {
    
    buffer.clear();
}

//==============================================================================
juce::AudioProcessorEditor* iphoneAudioAudioProcessor::createEditor() {
    
    return new iphoneAudioAudioProcessorEditor (*this);
}

bool iphoneAudioAudioProcessor::hasEditor() const {
    return true;
}

//==============================================================================
const juce::String iphoneAudioAudioProcessor::getName() const {
    return "iphone Audio";
}

bool iphoneAudioAudioProcessor::acceptsMidi() const {
    return true;
}
bool iphoneAudioAudioProcessor::producesMidi() const {
    return false;
}
bool iphoneAudioAudioProcessor::isMidiEffect() const {
    return false;
}
double iphoneAudioAudioProcessor::getTailLengthSeconds() const {
    return 0.0f;
}

//==============================================================================
int iphoneAudioAudioProcessor::getNumPrograms() {
    return 1;
}
int iphoneAudioAudioProcessor::getCurrentProgram() {
    return 0;
}

void iphoneAudioAudioProcessor::setCurrentProgram (int index) {
    
}

const juce::String iphoneAudioAudioProcessor::getProgramName (int index) {
    return {};
}
void iphoneAudioAudioProcessor::changeProgramName (int index, const juce::String& newName) {
    
}

//==============================================================================
void iphoneAudioAudioProcessor::getStateInformation (juce::MemoryBlock& destData) {
    
}
void iphoneAudioAudioProcessor::setStateInformation (const void* data, int sizeInBytes) {
    
}
