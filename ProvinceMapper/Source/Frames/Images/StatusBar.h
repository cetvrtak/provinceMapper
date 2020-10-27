#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

wxDECLARE_EVENT(wxEVT_TOGGLE_TRIANGULATE, wxCommandEvent);

class Configuration;
class StatusBar: public wxFrame
{
  public:
	StatusBar(wxWindow* parent, const wxPoint& position, std::shared_ptr<Configuration> theConfiguration);

	void setSourceZoom(int zoomLevel) const;
	void setTargetZoom(int zoomLevel) const;
	void setPointPlaced(int pointID);
	void setTriangulationSane(bool sane);

	[[nodiscard]] auto isTriangulate() const { return triangulate; }

  private:
	void onMove(wxMoveEvent& event);

	bool triangulate = false;

	wxTextCtrl* sourceZoomField = nullptr;
	wxTextCtrl* targetZoomField = nullptr;
	wxButton* triangulateButton = nullptr;

	wxWindow* sTriangulate1 = nullptr;
	wxWindow* sTriangulate2 = nullptr;
	wxWindow* sTriangulate3 = nullptr;
	wxWindow* tTriangulate1 = nullptr;
	wxWindow* tTriangulate2 = nullptr;
	wxWindow* tTriangulate3 = nullptr;
	wxStaticText* triangulateText = nullptr;

	void onZoomChanged(wxCommandEvent& evt);
	void onZoomResetButton(wxCommandEvent& evt);
	void onTriangulate(wxCommandEvent& evt);
	void onClose(wxCloseEvent& event);

	std::shared_ptr<Configuration> configuration;

  protected:
	wxEvtHandler* eventHandler = nullptr;
};
