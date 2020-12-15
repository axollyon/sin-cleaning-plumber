#include "src/game/envfx_snow.h"

const GeoLayout zeroninethree_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(1, 150, 40),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, zeroninethree_SCP_093_mesh),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, zeroninethree_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
