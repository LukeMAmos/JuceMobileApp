#include "DraggableComponent.h"

DraggableComponent::DraggableComponent(){
    
    setWantsKeyboardFocus(true);

}

void DraggableComponent::mouseDown(const juce::MouseEvent &event){
    
    dragger.startDraggingComponent(this, event);

    
}

void DraggableComponent::mouseDrag(const juce::MouseEvent &event){
    
    dragger.dragComponent(this, event, nullptr);

}

void DraggableComponent::mouseUp(const juce::MouseEvent &event){
    
}


void DraggableComponent::paint(juce::Graphics &g){
    
    g.setColour (juce::Colours::blue);

    g.fillEllipse(0, 0, diameter, diameter);
}

void DraggableComponent::resized(){

}

void DraggableComponent::setDiameter(float diameterIn){
    
    diameter = diameterIn; 
}

float DraggableComponent::getDiameter(){
    
    return diameter;
}
