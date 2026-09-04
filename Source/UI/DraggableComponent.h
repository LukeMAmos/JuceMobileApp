#include <JuceHeader.h>

class DraggableComponent : public juce::Component
{
    
public:
    DraggableComponent();
    
    void mouseDown(const juce::MouseEvent& event) override ;
    
    void mouseDrag(const juce::MouseEvent& event) override ;
    
    void mouseUp(const juce::MouseEvent& event)override;
    
    void paint(juce::Graphics& g )override;
    
    void resized() override;
    
    float getPositionXCentre(){return (float)getX() + diameter / 2.0f;}
    float getPositionYCentre(){return (float)getY() + diameter / 2.0f;}
    
    bool mDown = false;
    
    void setDiameter(float diameterIn);
    float getDiameter();
private:
    
    float diameter = 100;
    
    juce::ComponentDragger dragger;
    
};
