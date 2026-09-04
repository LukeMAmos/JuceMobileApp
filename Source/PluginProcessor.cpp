
#include "PluginProcessor.h"
#include "PluginEditor.h"

iphoneAudioAudioProcessor::iphoneAudioAudioProcessor(): AudioProcessor (BusesProperties()
.withOutput ("Output", juce::AudioChannelSet::stereo(), true)){
    
    
}
iphoneAudioAudioProcessor::~iphoneAudioAudioProcessor() {}

//==============================================================================
void iphoneAudioAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock) {
    
    juce::dsp::ProcessSpec processSpec;
    processSpec.sampleRate = sampleRate;
    processSpec.numChannels = 2;
    processSpec.maximumBlockSize = (uint32)samplesPerBlock;
    
    Synth.prepare(processSpec);
    
    
    /**
    juce::dsp::ProcessSpec procSpec;
    procSpec.sampleRate = sampleRate;
    procSpec.numChannels = (juce::uint32)getTotalNumOutputChannels();
    procSpec.maximumBlockSize = (juce::uint32)samplesPerBlock;
    
    // Initialise the raw oscillator as a clean sine wave
    testOsc.prepare(procSpec);
    testOsc.initialise([](float x) { return std::sin(x); });
    testOsc.setFrequency(440.0f); // 440 Hz **/
    
    
}
void iphoneAudioAudioProcessor::releaseResources() {
    
}

bool iphoneAudioAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const {
    
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}

void iphoneAudioAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiBuffer) {
    
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    buffer.clear();
    
    Synth.renderNextBlock(buffer, 0, buffer.getNumSamples());
    
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
