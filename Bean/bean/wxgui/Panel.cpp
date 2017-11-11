#include "Panel.h"

//public method---
Panel::Panel(ContainerInterface* parent) 
 : Container<PanelPeer>(new PanelPeer(parent->getWindow())){
}

Panel::~Panel() {
}
//---public method