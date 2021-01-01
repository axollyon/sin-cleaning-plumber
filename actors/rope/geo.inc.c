#include "src/game/envfx_snow.h"

const GeoLayout rope_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rope_Rope_Object_mesh),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rope_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
