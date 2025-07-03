#include <CTRPluginFramework.hpp>

namespace CTRPluginFramework {
    static u32 *uniformAddr = reinterpret_cast<u32 *>(0x00300044);
    static bool forceVisitor = false;

    void OnFrameCallback() {
        if (forceVisitor && uniformAddr && *uniformAddr == 0x00000004)
            *uniformAddr = 0x00000005;
    }

    void InitMenu(PluginMenu &menu) {
        MenuFolder *folder = new MenuFolder("Uniformes", "Opciones de uniforme");
        MenuEntry *entry = new MenuEntry("Forzar uniforme visitante", "Activa el uniforme de visitante");
        entry->SetActivation([](MenuEntry *e) {
            forceVisitor = e->IsActivated();
        });
        folder->Add(entry);
        menu += folder;
    }

    int main(void) {
        PluginMenu *menu = new PluginMenu("Uniforme visitante", 1, 0, 0);
        InitMenu(*menu);
        menu->Callback(OnFrameCallback);
        menu->Run();
        delete menu;
        return 0;
    }
}
