#include <JuceHeader.h>

class draggableComponent : public juce::Component
{
    
public:
    draggableComponent();
    
    void mouseDown(const juce::MouseEvent& event) override ;
    
    void mouseDrag(const juce::MouseEvent& event) override ;
    
    void mouseUp(const juce::MouseEvent& event)override;
    
    void paint(juce::Graphics& g )override;
    
    void resized() override;
    
    
    
    int getPositionXCentre(){return getX() + diameter / 2;};
    int getPositionYCentre(){return getY() + diameter / 2;};
    
    bool mDown = false;
    juce::Slider slider;
private:
    
    int diameter = 100;
    
    juce::ComponentDragger dragger;
    
};
