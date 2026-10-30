
/* WARNING: Switch with 1 destination removed at 0x001075a0 */

void __thiscall WSConn::connect(WSConn *this,long param_2)

{
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *this_00;
  _Rb_tree_node_base *p_Var1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  byte bVar7;
  code *pcVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  undefined8 *puVar12;
  long lVar13;
  _Rb_tree_node_base *p_Var14;
  _Rb_tree_node_base *p_Var15;
  sbyte sVar16;
  _Rb_tree_node_base *p_Var17;
  long lVar18;
  _Rb_tree_node_base *p_Var19;
  _Rb_tree_node_base *p_Var20;
  bool bVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  undefined1 auVar25 [16];
  int aiStack_108 [4];
  byte abStack_f8 [16];
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  code *pcStack_d8;
  undefined8 uStack_d0;
  char acStack_c8 [48];
  WSConn *pWStack_98;
  undefined1 auStack_90 [16];
  code *pcStack_80;
  undefined8 uStack_78;
  WSConn *pWStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  code *pcStack_50;
  undefined8 uStack_48;
  
  uVar9 = 0;
  abStack_f8[0] = 0;
  abStack_f8[1] = 0;
  abStack_f8[2] = 0;
  abStack_f8[3] = 0;
  abStack_f8[4] = 0;
  abStack_f8[5] = 0;
  abStack_f8[6] = 0;
  abStack_f8[7] = 0;
  abStack_f8[8] = 0;
  abStack_f8[9] = 0;
  abStack_f8[10] = 0;
  abStack_f8[0xb] = 0;
  abStack_f8[0xc] = 0;
  abStack_f8[0xd] = 0;
  abStack_f8[0xe] = 0;
  abStack_f8[0xf] = 0;
  pcVar11 = acStack_c8;
  iVar22 = 0;
  do {
    if (iVar22 + 1 == 0x10) {
      iVar23 = 0x10;
      sVar16 = 0x10;
      iVar22 = 1;
    }
    else {
      uVar9 = (uint)abStack_f8[iVar22 + 1] | uVar9 << 8;
      iVar23 = iVar22 + 2;
      if (iVar23 < 0x10) {
        lVar18 = (long)iVar23;
        iVar23 = iVar22 + 3;
        sVar16 = 0;
        uVar9 = uVar9 << 8 | (uint)abStack_f8[lVar18];
        iVar22 = 3;
      }
      else {
        sVar16 = 8;
        iVar22 = 2;
      }
    }
    uVar9 = uVar9 << sVar16;
    bVar7 = (byte)((int)uVar9 >> 0x12);
    pWStack_68 = (WSConn *)(CONCAT71((int7)((ulong)pWStack_68 >> 8),bVar7) & 0xffffffff0000003f);
    *pcVar11 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
               [(char)(bVar7 & 0x3f)];
    bVar7 = (byte)((int)uVar9 >> 0xc);
    pWStack_68 = (WSConn *)
                 (CONCAT62(pWStack_68._2_6_,CONCAT11(bVar7,pWStack_68._0_1_)) & 0xffffffffffff3fff);
    pcVar11[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                 [(char)(bVar7 & 0x3f)];
    if (iVar22 == 1) {
      pcVar11[2] = '=';
LAB_001124de:
      uVar9 = 0x40;
    }
    else {
      bVar7 = (byte)((int)uVar9 >> 6);
      pWStack_68 = (WSConn *)
                   (CONCAT53(pWStack_68._3_5_,CONCAT12(bVar7,pWStack_68._0_2_)) & 0xffffffffff3fffff
                   );
      pcVar11[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                   [(char)(bVar7 & 0x3f)];
      if (iVar22 != 3) goto LAB_001124de;
      uVar9 = uVar9 & 0x3f;
    }
    pcVar11[3] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="[(int)uVar9];
    if (0xf < iVar23) break;
    uVar9 = (uint)abStack_f8[iVar23];
    pcVar11 = pcVar11 + 4;
    iVar22 = iVar23;
  } while( true );
  pcVar11[4] = '\0';
  pcVar11 = operator_new(0x18);
  pcVar11[0] = '\0';
  pcVar11[1] = '\0';
  pcVar11[2] = '\0';
  pcVar11[3] = '\0';
  pcVar11[4] = '\0';
  pcVar11[5] = '\0';
  pcVar11[6] = '\0';
  pcVar11[7] = '\0';
  pcVar11[8] = '\0';
  pcVar11[9] = '\0';
  pcVar11[10] = '\0';
  pcVar11[0xb] = '\0';
  pcVar11[0xc] = '\0';
  pcVar11[0xd] = '\0';
  pcVar11[0xe] = '\0';
  pcVar11[0xf] = '\0';
  pcVar11[0x10] = '\0';
  pcVar11[0x11] = '\0';
  pcVar11[0x12] = '\0';
  pcVar11[0x13] = '\0';
  pcVar11[0x14] = '\0';
  pcVar11[0x15] = '\0';
  pcVar11[0x16] = '\0';
  pcVar11[0x17] = '\0';
  Buffer::appendf(pcVar11,
                  "GET / HTTP/1.1\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nSec-WebSocket-Key: %s\r\nSec-WebSocket-Extensions: permessage-deflate\r\nSec-WebSocket-Version: 13\r\n\r\n"
                  ,acStack_c8);
  pcStack_80 = (code *)0x0;
  pWStack_98 = this;
  if (*(code **)(param_2 + 0x10) != (code *)0x0) {
    (**(code **)(param_2 + 0x10))(auStack_90,param_2,2);
    uStack_78 = *(undefined8 *)(param_2 + 0x18);
    pcStack_80 = *(code **)(param_2 + 0x10);
  }
  lVar18 = *(long *)(this + 0x38);
  if (*(char *)(lVar18 + 0x5a) != '\0') {
    fwrite("send(): send_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    print_stack();
  }
  puVar12 = *(undefined8 **)(lVar18 + 0x60);
  *(undefined1 *)(lVar18 + 0x5a) = 1;
  *(char **)(lVar18 + 0x60) = pcVar11;
  if (puVar12 != (undefined8 *)0x0) {
    if ((void *)*puVar12 != (void *)0x0) {
      operator_delete((void *)*puVar12);
    }
    operator_delete(puVar12);
  }
  pcStack_50 = (code *)0x0;
  pWStack_68 = pWStack_98;
  if (pcStack_80 != (code *)0x0) {
    (*pcStack_80)(&uStack_60,auStack_90,2);
    uStack_48 = uStack_78;
    pcStack_50 = pcStack_80;
  }
  pcStack_d8 = (code *)0x0;
  puVar12 = operator_new(0x28);
  pcVar8 = pcStack_50;
  uVar3 = puVar12[1];
  puVar12[3] = 0;
  uVar4 = puVar12[2];
  *puVar12 = pWStack_68;
  puVar12[1] = uStack_60;
  puVar12[2] = uStack_58;
  pcStack_50 = (code *)0x0;
  uVar5 = puVar12[4];
  puVar12[3] = pcVar8;
  puVar12[4] = uStack_48;
  uStack_e8 = *(undefined8 *)(lVar18 + 0x68);
  uVar6 = *(undefined8 *)(lVar18 + 0x70);
  *(undefined8 *)(lVar18 + 0x70) = uStack_e0;
  *(undefined8 **)(lVar18 + 0x68) = puVar12;
  pcStack_d8 = *(code **)(lVar18 + 0x78);
  uStack_d0 = *(undefined8 *)(lVar18 + 0x80);
  *(code **)(lVar18 + 0x78) = FUN_0010e2d0;
  *(code **)(lVar18 + 0x80) = FUN_0010fd40;
  uStack_e0 = uVar6;
  uStack_60 = uVar3;
  uStack_58 = uVar4;
  uStack_48 = uVar5;
  if (pcStack_d8 != (code *)0x0) {
    (*pcStack_d8)(&uStack_e8,&uStack_e8,3);
  }
  if (pcStack_50 != (code *)0x0) {
    (*pcStack_50)(&uStack_60,&uStack_60,3);
  }
  aiStack_108[0] = *(int *)(lVar18 + 0x40);
  cVar2 = *(char *)(lVar18 + 0x5a);
  lVar18 = *(long *)(lVar18 + 0x38);
  p_Var15 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var14 = (_Rb_tree_node_base *)(lVar18 + 0x10);
  p_Var20 = p_Var15;
  p_Var19 = p_Var14;
  if (p_Var15 == (_Rb_tree_node_base *)0x0) {
LAB_00112a70:
    lVar13 = 0;
    uVar9 = 0;
  }
  else {
    do {
      while (p_Var17 = p_Var20, aiStack_108[0] <= *(int *)(p_Var17 + 0x20)) {
        p_Var20 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var19 = p_Var17;
        if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_0011275b;
      }
      p_Var1 = p_Var17 + 0x18;
      p_Var20 = *(_Rb_tree_node_base **)p_Var1;
      p_Var17 = p_Var19;
    } while (*(_Rb_tree_node_base **)p_Var1 != (_Rb_tree_node_base *)0x0);
LAB_0011275b:
    if ((p_Var14 == p_Var17) || (p_Var20 = p_Var14, aiStack_108[0] < *(int *)(p_Var17 + 0x20)))
    goto LAB_00112a70;
    do {
      while (p_Var19 = p_Var15, aiStack_108[0] <= *(int *)(p_Var19 + 0x20)) {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var19 + 0x10);
        p_Var20 = p_Var19;
        if (*(_Rb_tree_node_base **)(p_Var19 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_00112793;
      }
      p_Var17 = p_Var19 + 0x18;
      p_Var15 = *(_Rb_tree_node_base **)p_Var17;
      p_Var19 = p_Var20;
    } while (*(_Rb_tree_node_base **)p_Var17 != (_Rb_tree_node_base *)0x0);
LAB_00112793:
    if ((p_Var14 == p_Var19) || (aiStack_108[0] < *(int *)(p_Var19 + 0x20))) {
      p_Var15 = operator_new(0x28);
      if (p_Var15 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var15 = 0;
        *(undefined8 *)(p_Var15 + 8) = 0;
        *(undefined8 *)(p_Var15 + 0x10) = 0;
        *(undefined8 *)(p_Var15 + 0x18) = 0;
        *(undefined4 *)(p_Var15 + 0x24) = 0;
        *(int *)(p_Var15 + 0x20) = aiStack_108[0];
      }
      auVar25 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(lVar18 + 8),p_Var19,p_Var15 + 0x20);
      p_Var20 = auVar25._8_8_;
      p_Var19 = auVar25._0_8_;
      if (p_Var20 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var15);
      }
      else {
        bVar21 = true;
        if ((p_Var19 == (_Rb_tree_node_base *)0x0) && (p_Var14 != p_Var20)) {
          bVar21 = *(int *)(p_Var15 + 0x20) < *(int *)(p_Var20 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar21,p_Var15,p_Var20,p_Var14);
        *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
        p_Var19 = p_Var15;
      }
    }
    uVar9 = *(uint *)(p_Var19 + 0x24);
    lVar13 = 1;
  }
  lVar18 = lVar18 + (lVar13 + 1) * 0x30;
  this_00 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
             *)(lVar18 + 8);
  p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var19 = (_Rb_tree_node_base *)(lVar18 + 0x10);
  p_Var15 = p_Var14;
  p_Var20 = p_Var19;
  uVar10 = uVar9;
  if (p_Var14 != (_Rb_tree_node_base *)0x0) {
    do {
      while (p_Var17 = p_Var15, aiStack_108[0] <= *(int *)(p_Var17 + 0x20)) {
        p_Var15 = *(_Rb_tree_node_base **)(p_Var17 + 0x10);
        p_Var20 = p_Var17;
        if (*(_Rb_tree_node_base **)(p_Var17 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_001127fa;
      }
      p_Var1 = p_Var17 + 0x18;
      p_Var15 = *(_Rb_tree_node_base **)p_Var1;
      p_Var17 = p_Var20;
    } while (*(_Rb_tree_node_base **)p_Var1 != (_Rb_tree_node_base *)0x0);
LAB_001127fa:
    if ((p_Var19 != p_Var17) && (p_Var15 = p_Var19, *(int *)(p_Var17 + 0x20) <= aiStack_108[0])) {
      do {
        while (p_Var20 = p_Var14, aiStack_108[0] <= *(int *)(p_Var20 + 0x20)) {
          p_Var14 = *(_Rb_tree_node_base **)(p_Var20 + 0x10);
          p_Var15 = p_Var20;
          if (*(_Rb_tree_node_base **)(p_Var20 + 0x10) == (_Rb_tree_node_base *)0x0)
          goto LAB_0011282a;
        }
        p_Var17 = p_Var20 + 0x18;
        p_Var14 = *(_Rb_tree_node_base **)p_Var17;
        p_Var20 = p_Var15;
      } while (*(_Rb_tree_node_base **)p_Var17 != (_Rb_tree_node_base *)0x0);
LAB_0011282a:
      if ((p_Var19 == p_Var20) || (aiStack_108[0] < *(int *)(p_Var20 + 0x20))) {
        p_Var14 = operator_new(0x28);
        if (p_Var14 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var14 = 0;
          *(undefined8 *)(p_Var14 + 8) = 0;
          *(undefined8 *)(p_Var14 + 0x10) = 0;
          *(undefined8 *)(p_Var14 + 0x18) = 0;
          *(undefined4 *)(p_Var14 + 0x24) = 0;
          *(int *)(p_Var14 + 0x20) = aiStack_108[0];
        }
        auVar25 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(this_00,p_Var20,p_Var14 + 0x20);
        p_Var15 = auVar25._8_8_;
        p_Var20 = auVar25._0_8_;
        if (p_Var15 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var14);
        }
        else {
          bVar21 = true;
          if ((p_Var20 == (_Rb_tree_node_base *)0x0) && (p_Var19 != p_Var15)) {
            bVar21 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var15 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar21,p_Var14,p_Var15,p_Var19);
          *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
          p_Var20 = p_Var14;
        }
      }
      uVar10 = *(uint *)(p_Var20 + 0x24);
    }
  }
  uVar24 = uVar10 | 2;
  if (cVar2 == '\0') {
    uVar24 = uVar10 & 0xfffffffd;
  }
  if (uVar9 == uVar24) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(this_00,aiStack_108);
    goto LAB_00112919;
  }
  p_Var14 = *(_Rb_tree_node_base **)(lVar18 + 0x18);
  p_Var20 = p_Var19;
  p_Var15 = p_Var19;
  if (*(_Rb_tree_node_base **)(lVar18 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0011289c:
    p_Var14 = operator_new(0x28);
    if (p_Var14 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var14 = 0;
      *(undefined8 *)(p_Var14 + 8) = 0;
      *(undefined8 *)(p_Var14 + 0x10) = 0;
      *(undefined8 *)(p_Var14 + 0x18) = 0;
      *(undefined4 *)(p_Var14 + 0x24) = 0;
      *(int *)(p_Var14 + 0x20) = aiStack_108[0];
    }
    auVar25 = std::
              _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              ::_M_get_insert_hint_unique_pos(this_00,p_Var15,p_Var14 + 0x20);
    p_Var20 = auVar25._8_8_;
    p_Var15 = auVar25._0_8_;
    if (p_Var20 == (_Rb_tree_node_base *)0x0) {
      operator_delete(p_Var14);
    }
    else {
      bVar21 = true;
      if ((p_Var15 == (_Rb_tree_node_base *)0x0) && (p_Var19 != p_Var20)) {
        bVar21 = *(int *)(p_Var14 + 0x20) < *(int *)(p_Var20 + 0x20);
      }
      std::_Rb_tree_insert_and_rebalance(bVar21,p_Var14,p_Var20,p_Var19);
      *(long *)(lVar18 + 0x30) = *(long *)(lVar18 + 0x30) + 1;
      p_Var15 = p_Var14;
    }
  }
  else {
    do {
      while (p_Var15 = p_Var14, aiStack_108[0] <= *(int *)(p_Var15 + 0x20)) {
        p_Var14 = *(_Rb_tree_node_base **)(p_Var15 + 0x10);
        p_Var20 = p_Var15;
        if (*(_Rb_tree_node_base **)(p_Var15 + 0x10) == (_Rb_tree_node_base *)0x0)
        goto LAB_00112892;
      }
      p_Var17 = p_Var15 + 0x18;
      p_Var14 = *(_Rb_tree_node_base **)p_Var17;
      p_Var15 = p_Var20;
    } while (*(_Rb_tree_node_base **)p_Var17 != (_Rb_tree_node_base *)0x0);
LAB_00112892:
    if ((p_Var19 == p_Var15) || (aiStack_108[0] < *(int *)(p_Var15 + 0x20))) goto LAB_0011289c;
  }
  *(uint *)(p_Var15 + 0x24) = uVar24;
LAB_00112919:
  if (pcStack_80 != (code *)0x0) {
    (*pcStack_80)(auStack_90,auStack_90,3);
  }
  return;
}



