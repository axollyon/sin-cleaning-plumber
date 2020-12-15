// breakable_box.c.inc

struct ObjectHitbox sZeroNineThreeHitbox = {
    /* interactType:      */ INTERACT_GRABBABLE,
    /* downOffset:        */ 20,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 20,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 20,
    /* hurtboxHeight:     */ 250,
};

void bhv_zeroninethree_init(void) {
    o->oGravity = 50.0f;
    o->oFriction = 0.5f;
    o->oBuoyancy = 1.0;
    obj_set_hitbox(o, &sZeroNineThreeHitbox);
    o->oAnimState = 1;
}

#define SPEED 30

void zeroninethree_idle_loop(void) {
    object_step();
    obj_attack_collided_from_other_object(o);

    if (o->oPosZ > 880) {
        o->oPosZ = 880;
    }

    if (o->oPosX > o->oHomeX + SPEED / 2) {
        o->oPosX -= SPEED;
    }
    else if (o->oPosX < o->oHomeX - SPEED / 2) {
        o->oPosX += SPEED;
    }
    else if (o->oPosX != o->oHomeX) {
        o->oPosX = o->oHomeX;
    }
    if (o->oPosY > o->oHomeY + SPEED / 2) {
        o->oGravity = 0.0f;
        o->oVelY = 0.0f;
        o->oPosY -= SPEED;
    }
    else if (o->oPosY < o->oHomeY - SPEED / 2) {
        o->oGravity = 0.0f;
        o->oVelY = 0.0f;
        o->oPosY += SPEED;
    }
    else if (o->oPosY != o->oHomeY) {
        o->oPosY = o->oHomeY;
    }
    if (o->oPosZ > o->oHomeZ + SPEED / 2) {
        o->oPosZ -= SPEED;
    }
    else if (o->oPosZ < o->oHomeZ - SPEED / 2) {
        o->oPosZ += SPEED;
    }
    else if (o->oPosZ != o->oHomeZ) {
        o->oPosZ = o->oHomeZ;
    }
    if (
        o->oPosX < o->oHomeX + SPEED / 2 && o->oPosX > o->oHomeX - SPEED / 2 &&
        o->oPosY < o->oHomeY + SPEED / 2 && o->oPosY > o->oHomeY - SPEED / 2 &&
        o->oPosZ < o->oHomeZ + SPEED / 2 && o->oPosZ > o->oHomeZ - SPEED / 2
        ) {
        o->oGravity = 50.0f;
    }
}

void zeroninethree_get_dropped(void) {
    cur_obj_become_tangible();
    cur_obj_enable_rendering();
    cur_obj_get_dropped();
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oHeldState = 0;
}

void zeroninethree_get_thrown(void) {
    cur_obj_become_tangible();
    cur_obj_enable_rendering_2();
    cur_obj_enable_rendering();
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oHeldState = 0;
    o->oFlags &= ~0x08;
}

void bhv_zeroninethree_loop(void) {
    switch (o->oHeldState) {
        case 0:
            zeroninethree_idle_loop();
            break;

        case 1:
            o->oGravity = 50.0f;
            cur_obj_disable_rendering();
            cur_obj_become_intangible();
            break;

        case 2:
            zeroninethree_get_thrown();
            break;

        case 3:
            zeroninethree_get_dropped();
            break;
    }

    o->oInteractStatus = 0;
}
