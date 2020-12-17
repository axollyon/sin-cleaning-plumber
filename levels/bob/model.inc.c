Lights1 bob_dl_sm64_material_lights = gdSPDefLights1(
	0x63, 0x7F, 0x5E,
	0xC6, 0xFE, 0xBD, 0x28, 0x28, 0x28);

Vtx bob_dl_Ground_mesh_vtx_0[4] = {
	{{{-8000, 0, 8000},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8000, 0, 8000},0, {1008, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8000, 0, -8000},0, {1008, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-8000, 0, -8000},0, {-16, -16},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx bob_dl_Ground_mesh_tri_0[] = {
	gsSPVertex(bob_dl_Ground_mesh_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_bob_dl_sm64_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(bob_dl_sm64_material_lights),
	gsSPEndDisplayList(),
};


Gfx bob_dl_Ground_mesh[] = {
	gsSPDisplayList(mat_bob_dl_sm64_material),
	gsSPDisplayList(bob_dl_Ground_mesh_tri_0),
	gsSPEndDisplayList(),
};



Gfx bob_dl_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
