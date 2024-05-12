#include "ConnectionMenu.h"

auto connection_menu_method = [](float dt, World* world) {

    static bool show_window = true;
    static bool collapsed = true;
    static char text_buffer[256] = "";
    static char int_buffer[256] = "";

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::Begin("Connection", &show_window, ImGuiWindowFlags_None);

    if (collapsed){
        ImGui::SetWindowCollapsed(true);
        collapsed = false;
    }

    ImGui::InputText("IP address", text_buffer, sizeof(text_buffer));

    ImGui::InputText("Port", int_buffer, sizeof(text_buffer), ImGuiInputTextFlags_CharsDecimal);


    if (ImGui::Button("Connect")) {

        for (const auto &item: world->getEntities()){
            auto networking = item->getComponent<NetworkingC>();
            if (!networking) continue;

            networking->networking.createWorker<NetClient>(atoi(int_buffer), text_buffer);
        }

    }

    ImGui::End();
};

ConnectionMenu::ConnectionMenu() = default;

void ConnectionMenu::init(World* world) {
    this->world = world;

    auto connection_menu_renderer = world->createEntity();
    connection_menu_renderer->addComponent(make_shared<RenderMethod>(connection_menu_method));

}

void ConnectionMenu::update(float dt) {}