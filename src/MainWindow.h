/*
  NUI3 - C++ cross-platform GUI framework for OpenGL based applications
  Copyright (C) 2002-2003 Sebastien Metrot

  licence: see nui3/LICENCE.TXT
*/

#pragma once

#include "nuiMainWindow.h"
#include "ProcessTree.h"
#include "VariableNode.h"

class MainWindow : public nuiMainWindow
{
public:
  MainWindow(const nglContextInfo& rContext, const nglWindowInfo& rInfo, bool ShowFPS = false, const nglContext* pShared = NULL);
  ~MainWindow();

  void OnCreation();
  void OnClose();

  void UpdateProcess();
protected:
  bool LoadCSS(const nglPath& rPath);

  nuiEventSink<MainWindow> mEventSink;

  void OnStart(const nuiEvent& rEvent);
  void OnPause(const nuiEvent& rEvent);
  void OnContinue(const nuiEvent& rEvent);
  void OnThreadSelectionChanged(const nuiEvent& rEvent);
  void Loop();

  nglThreadDelegate* mpDebuggerEventLoop;

  nuiTreeView* mpThreads;
  nuiTreeView* mpVariables;

  void SelectProcess(lldb::SBProcess process);
  void SelectThread(lldb::SBThread thread);
  void SelectFrame(lldb::SBFrame frame);
  void UpdateVariables(lldb::SBFrame frame);
};

