#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/bob/header.h"

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_WOODEN_DOOR, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 

	AREA(1, bob_area_1),
		WARP_NODE(0xF0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 4447, 17136, 0, 0, 0, 0x640B0000, bhvWarp),
		OBJECT(MODEL_NONE, 0, 5214, -17136, 0, 0, 0, 0x000A0000, bhvInstantActiveWarp),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STREAMED_WELCOMING),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	AREA(2, bob_area_2),
		WARP_NODE(0xF0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE_GROUNDS, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0A, LEVEL_BOB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_HMC_WOODEN_DOOR, 0, 0, 2858, 0, -180, 0, 0x00FF0000, bhvDoor),
		OBJECT(MODEL_HMC_WOODEN_DOOR, 350, 0, -624, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_HMC_WOODEN_DOOR, 350, 0, -31, 0, -90, 0, 0x00FE0000, bhvDoor),
		OBJECT(MODEL_HMC_WOODEN_DOOR, 350, 0, 562, 0, -90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_HMC_WOODEN_DOOR, 350, 0, 1155, 0, -90, 0, 0x00FF0000, bhvDoor),
		OBJECT(MODEL_HMC_WOODEN_DOOR, 350, 0, 1748, 0, -90, 0, 0x00FF0000, bhvDoor),
		OBJECT(MODEL_HMC_WOODEN_DOOR, 350, 0, 2341, 0, -90, 0, 0x00FF0000, bhvDoor),
		OBJECT(MODEL_HMC_WOODEN_DOOR, -350, 0, -624, 0, 90, 0, 0x00FF0000, bhvDoor),
		OBJECT(MODEL_HMC_WOODEN_DOOR, -350, 0, -31, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_HMC_WOODEN_DOOR, -350, 0, 562, 0, 90, 0, 0x00FF0000, bhvDoor),
		OBJECT(MODEL_HMC_WOODEN_DOOR, -350, 0, 1155, 0, 90, 0, 0x00FF0000, bhvDoor),
		OBJECT(MODEL_HMC_WOODEN_DOOR, -350, 0, 1748, 0, 90, 0, 0x00FF0000, bhvDoor),
		OBJECT(MODEL_HMC_WOODEN_DOOR, -350, 0, 2341, 0, 90, 0, 0x00FF0000, bhvDoor),
		OBJECT(MODEL_NONE, 0, 380, -7000, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_2_collision),
		ROOMS(bob_area_2_collision_rooms),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STREAMED_WELCOMING),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
