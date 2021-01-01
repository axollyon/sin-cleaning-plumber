#include "src/game/envfx_snow.h"

const GeoLayout unclean_figure_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(1, 145, 100),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, unclean_figure_BASE_Low_Poly_Man_mesh),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, unclean_figure_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
