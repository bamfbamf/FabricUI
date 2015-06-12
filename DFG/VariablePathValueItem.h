// Copyright 2010-2015 Fabric Software Inc. All rights reserved.

#ifndef __UI_DFG_VariablePathValueItem__
#define __UI_DFG_VariablePathValueItem__

#include <FabricUI/ValueEditor/ValueItem.h>
#include <map>

#include <FabricCore.h>

namespace FabricUI
{

  namespace DFG
  {
    class VariablePathValueItem : public ValueEditor::ValueItem
    {
      Q_OBJECT

    public:

      VariablePathValueItem(QString name, TreeView::TreeEditorFactory * factory, FabricCore::Client * client, FabricCore::DFGBinding binding, QWidget * parent, FabricCore::RTVal value, QString label = "", bool enabled = true);

      virtual QString type() const { return "VariablePath"; }

      FabricCore::DFGBinding getDFGBinding() { return m_binding; }

    private:

      FabricCore::DFGBinding m_binding;
    };

  };

};

#endif // __UI_DFG_VariablePathValueItem__