#include "src/game/envfx_snow.h"

const GeoLayout questionmark_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BILLBOARD_WITH_PARAMS(LAYER_TRANSPARENT, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_SHADOW(1, 150, 150),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, questionmark_Question_Mark_mesh),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, questionmark_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
