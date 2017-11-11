#include "ScrollPane.h"
#include "ContainerInterface.h"

//public method---
ScrollPane::ScrollPane(ContainerInterface* containerInterface) 
 : Container<ScrollPanePeer>(new ScrollPanePeer(containerInterface->getWindow())) {
}

ScrollPane::~ScrollPane() {
}
//---public method