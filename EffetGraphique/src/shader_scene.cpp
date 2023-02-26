#include <imgui.h>

#include "platform.h"
#include "color.h"
#include "shader_scene.h"

shader_scene::shader_scene(GL::cache& GLCache)
{
    // Init light
    {
        this->Light.Enabled = true;
        this->Light.Position = { 1.f, 1.f, 1.f, 0.f };
        this->Light.Ambient = { 0.2f, 0.2f, 0.2f };
        this->Light.Diffuse = { 0.0f, 0.0f, 1.0f };
        this->Light.Specular = { 1.0f, 0.0f, 0.0f };
    }

    // Create mesh
    {
        // Use vbo from GLCache
        MeshBuffer = GLCache.LoadObj("media/ball.obj", 1.f, &this->MeshVertexCount);

        MeshDesc.Stride = sizeof(vertex_full);
        MeshDesc.HasNormal = true;
        MeshDesc.HasUV = true;
        MeshDesc.PositionOffset = OFFSETOF(vertex_full, Position);
        MeshDesc.UVOffset = OFFSETOF(vertex_full, UV);
        MeshDesc.NormalOffset = OFFSETOF(vertex_full, Normal);
    }

    // Gen light uniform buffer
    {
        glGenBuffers(1, &LightsUniformBuffer);
        glBindBuffer(GL_UNIFORM_BUFFER, LightsUniformBuffer);
        glBufferData(GL_UNIFORM_BUFFER, sizeof(GL::light), &Light, GL_DYNAMIC_DRAW);
    }
}

shader_scene::~shader_scene()
{
    glDeleteBuffers(1, &LightsUniformBuffer);
    glDeleteBuffers(1, &MeshBuffer); // From cache
}

static bool EditLight(GL::light* Light)
{
    bool Result =
        ImGui::Checkbox("Enabled", (bool*)&Light->Enabled)
        + ImGui::SliderFloat4("Position", Light->Position.e, -10.f, 10.f);
        + ImGui::ColorEdit3("Ambient", Light->Ambient.e)
        + ImGui::ColorEdit3("Diffuse", Light->Diffuse.e)
        + ImGui::ColorEdit3("Specular", Light->Specular.e);

    return Result;
}

void shader_scene::InspectLights()
{
    if (ImGui::TreeNode(&Light, "Light"))
    {
        if (EditLight(&Light))
            glBufferSubData(GL_UNIFORM_BUFFER, 0 * sizeof(GL::light), sizeof(GL::light), &Light);

        ImGui::TreePop();
    }
}