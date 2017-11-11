#include "WxFrameEx.h"
#include <iostream>

//public method---
WxFrameEx::WxFrameEx(const wxString& title, int width, int height) 
 : wxFrame(NULL,
		   wxID_ANY,
		   title,
		   wxDefaultPosition,
		   wxSize(width, height)
	) {
	this->contentPane = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
//	this->Set
	wxSizer* hSizer = new wxBoxSizer(wxHORIZONTAL);
	hSizer->Add(contentPane);
	SetSizer(hSizer);

	this->SetAutoLayout(true);
}

WxFrameEx::~WxFrameEx() {
}

wxPanel * WxFrameEx::getContentPane() const {
	return contentPane;
}

void WxFrameEx::OnClose(wxCommandEvent & e) {
	Close(true);
	Destroy();
}
//---public method