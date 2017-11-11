#include "UserPanel.h"
#include "../../wxgui/ContainerInterface.h"
#include "../../wxgui/PanelInterface.h"

//public method---
UserPanel::UserPanel(PanelInterface* panelInterface) 
 : UserContainer(dynamic_cast<ContainerInterface*>(panelInterface)) {
}

UserPanel::~UserPanel() {
	delete panelInterface;
}
//---public method