#include "DraggableComponent.hpp"

draggableComponent::draggableComponent(){
    
    setWantsKeyboardFocus(true);
    
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    slider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    
    addAndMakeVisible(slider);
    //Constructor
}

void draggableComponent::mouseDown(const juce::MouseEvent &event){
    
    dragger.startDraggingComponent(this, event);

    
}

void draggableComponent::mouseDrag(const juce::MouseEvent &event){
    
    dragger.dragComponent(this, event, nullptr);

}

void draggableComponent::mouseUp(const juce::MouseEvent &event){

    
}


void draggableComponent::paint(juce::Graphics &g){
    
    std::cout<<"Here is myX :"<<getX() <<"\n";
    
    g.setColour (juce::Colours::blue);

    g.fillEllipse(0, 0, diameter, diameter);
}

void draggableComponent::resized(){
    
    slider.setBounds(( getWidth() /2 ) - 35, (getHeight() / 2) - 35 , 70, 70);
}
