// Copyright 2010-2015 Fabric Software Inc. All rights reserved.

#ifndef __UI_DFG_DFGUICmd_RenameNode__
#define __UI_DFG_DFGUICmd_RenameNode__

#include <FabricUI/DFG/DFGUICmd/DFGUICmd_Exec.h>

FABRIC_UI_DFG_NAMESPACE_BEGIN

class DFGUICmd_RenameNode
  : public DFGUICmd_Exec
{
public:

  DFGUICmd_RenameNode(
    FabricCore::DFGBinding const &binding,
    FTL::StrRef execPath,
    FabricCore::DFGExec const &exec,
    FTL::StrRef oldNodeName,
    FTL::StrRef desiredNewNodeName
    )
    : DFGUICmd_Exec(
      binding,
      execPath,
      exec
      )
    , m_oldNodeName( oldNodeName )
    , m_desiredNewNodeName( desiredNewNodeName )
    {}

  static FTL::CStrRef CmdName()
    { return DFG_CMD_NAME("RenameNode"); }

  FTL::CStrRef getActualNewNodeName() const
    { return m_actualNewNodeName; }
  
protected:
  
  virtual void appendDesc( std::string &desc );
  
  virtual void invoke( unsigned &coreUndoCount );

private:

  std::string m_oldNodeName;
  std::string m_desiredNewNodeName;

  std::string m_actualNewNodeName;
};

FABRIC_UI_DFG_NAMESPACE_END

#endif // __UI_DFG_DFGUICmd_RenameNode__
