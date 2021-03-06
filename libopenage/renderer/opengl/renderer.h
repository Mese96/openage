// Copyright 2017-2018 the openage authors. See copying.md for legal info.

#pragma once

#include <memory>

#include <SDL2/SDL.h>

#include "context.h"
#include "../renderer.h"
#include "shader_program.h"
#include "render_target.h"


namespace openage {
namespace renderer {
namespace opengl {

/// The OpenGL specialization of the rendering interface.
class GlRenderer final : public Renderer {
public:
	GlRenderer(GlContext*);

	std::unique_ptr<Texture2d> add_texture(resources::Texture2dData const&) override;
	std::unique_ptr<Texture2d> add_texture(resources::Texture2dInfo const&) override;

	std::unique_ptr<ShaderProgram> add_shader(std::vector<resources::ShaderSource> const&) override;

	std::unique_ptr<Geometry> add_mesh_geometry(resources::MeshData const&) override;
	std::unique_ptr<Geometry> add_bufferless_quad() override;

	std::unique_ptr<RenderTarget> create_texture_target(std::vector<Texture2d*>) override;
	RenderTarget const* get_display_target() override;

	resources::Texture2dData display_into_data() override;

	void render(RenderPass const&) override;

private:
	/// The GL context.
	GlContext *gl_context;

	GlRenderTarget display;
};

}}} // openage::renderer::opengl
