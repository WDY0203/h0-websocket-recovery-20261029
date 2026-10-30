
void FUN_00112b60(long *param_1,int param_2)

{
  _Rb_tree_node_base *p_Var1;
  ulong uVar2;
  int *piVar3;
  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
  *p_Var4;
  uint *puVar5;
  char cVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  void *pvVar15;
  long *plVar16;
  char *pcVar17;
  undefined8 *puVar18;
  void *pvVar19;
  long lVar20;
  _Rb_tree_node_base *p_Var21;
  _Rb_tree_node_base *p_Var22;
  sbyte sVar23;
  long lVar24;
  _Rb_tree_node_base *p_Var25;
  ulong uVar26;
  uint *puVar27;
  size_t __n;
  char *pcVar28;
  ulong uVar29;
  _Rb_tree_node_base *p_Var30;
  int iVar31;
  char *pcVar32;
  char cVar33;
  uint uVar34;
  long lVar35;
  _Rb_tree_node_base *p_Var36;
  uint *puVar37;
  bool bVar38;
  byte bVar39;
  undefined1 auVar40 [16];
  int local_218 [4];
  undefined *local_208 [2];
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined8 local_1e8;
  undefined8 local_1e0;
  char local_1d8 [48];
  string local_1a8;
  byte bStack_1a7;
  byte bStack_1a6;
  byte bStack_1a5;
  undefined4 uStack_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  int local_194;
  undefined8 local_190;
  long local_188;
  undefined1 local_154;
  undefined1 local_153;
  undefined1 local_152;
  undefined1 local_151;
  undefined1 local_150;
  undefined1 local_14f;
  undefined1 local_14e;
  undefined1 local_14d;
  int local_14c;
  int local_148;
  int local_144;
  undefined1 auStack_13b [8];
  undefined1 auStack_133 [8];
  undefined1 auStack_12b [3];
  undefined1 local_128 [8];
  undefined1 auStack_120 [8];
  undefined8 local_118;
  
  bVar39 = 0;
  param_1 = (long *)*param_1;
  pvVar15 = (void *)**(undefined8 **)(*param_1 + 0x40);
  iVar12 = (int)(*(undefined8 **)(*param_1 + 0x40))[1] - (int)pvVar15;
  pvVar15 = memmem(pvVar15,(long)iVar12,"Sec-WebSocket-Key: ",0x13);
  if (pvVar15 != (void *)0x0) {
    lVar24 = 0;
    do {
      cVar33 = *(char *)((long)pvVar15 + lVar24 + 0x13);
      if (((cVar33 == '\r') || (cVar33 == '\n')) || (iVar31 = (int)lVar24, iVar12 + -0x13 <= iVar31)
         ) goto LAB_00112bdb;
      auStack_13b[lVar24 + 3] = cVar33;
      lVar24 = lVar24 + 1;
    } while (lVar24 != 0x7f);
    lVar24 = (long)(iVar31 + 1);
LAB_00112bdb:
    auStack_13b[lVar24 + 3] = 0;
    if (auStack_13b[3] != '\0') {
      puVar5 = (uint *)(auStack_13b + 3);
      puVar37 = puVar5;
      do {
        puVar27 = puVar37;
        uVar13 = *puVar27 + 0xfefefeff & ~*puVar27;
        uVar14 = uVar13 & 0x80808080;
        puVar37 = puVar27 + 1;
      } while (uVar14 == 0);
      local_194 = 0;
      bVar38 = (uVar13 & 0x8080) == 0;
      local_190 = (code *)((ulong)local_190 & 0xffffffff00000000);
      if (bVar38) {
        uVar14 = uVar14 >> 0x10;
      }
      local_14c = 0;
      local_1a8 = (string)0x1;
      bStack_1a7 = 0x23;
      bStack_1a6 = 0x45;
      bStack_1a5 = 0x67;
      uStack_1a4 = 0xefcdab89;
      if (bVar38) {
        puVar37 = (uint *)((long)puVar27 + 6);
      }
      local_1a0 = 0x98badcfe;
      local_19c = 0x10325476;
      local_198 = 0xc3d2e1f0;
      lVar24 = (long)puVar37 + ((-3 - (ulong)CARRY1((byte)uVar14,(byte)uVar14)) - (long)puVar5);
      local_148 = 0;
      local_144 = 0;
      *(undefined8 *)((long)puVar5 + lVar24) = 0x3541464145383532;
      *(undefined4 *)(auStack_120 + lVar24 + 8) = 0x31314235;
      *(undefined8 *)(auStack_133 + lVar24 + 3) = 0x37342d343139452d;
      *(undefined1 *)((long)&local_118 + lVar24 + 4) = 0;
      *(undefined8 *)(auStack_12b + lVar24 + 3) = 0x2d414335392d4144;
      *(undefined8 *)(local_128 + lVar24 + 8) = 0x3843443042413543;
      if ((int)lVar24 == -0x24) {
LAB_001135da:
        iVar31 = local_14c;
        iVar12 = local_14c + 1;
        lVar24 = (long)local_14c;
        local_14c = iVar12;
        *(undefined1 *)((long)&local_190 + lVar24 + 4) = 0x80;
        if (iVar31 < 0x38) {
          if (iVar12 != 0x38) {
            memset((void *)((long)&local_190 + lVar24 + 5),0,(ulong)(0x37 - iVar31));
            local_14c = 0x38;
          }
        }
        else {
          if (iVar12 < 0x40) {
            memset((void *)((long)&local_190 + lVar24 + 5),0,(ulong)(0x3f - iVar31));
            local_14c = 0x40;
          }
          FUN_0010d620(&local_1a8);
          if (local_14c < 0x38) {
            memset((void *)((long)&local_190 + (long)local_14c + 4),0,(ulong)(0x38 - local_14c));
            local_14c = 0x38;
          }
        }
        local_151 = SUB81(local_190,0);
        local_154 = (undefined1)((ulong)local_190 >> 0x18);
        local_153 = (undefined1)((ulong)local_190 >> 0x10);
        local_152 = (undefined1)((ulong)local_190 >> 8);
        local_14d = (undefined1)local_194;
        local_150 = (undefined1)((uint)local_194 >> 0x18);
        local_14f = (undefined1)((uint)local_194 >> 0x10);
        local_14e = (undefined1)((uint)local_194 >> 8);
        FUN_0010d620(&local_1a8);
LAB_001136c1:
        uVar14 = (uint)bStack_1a5;
        local_1f8._0_3_ = CONCAT12(bStack_1a7,CONCAT11(bStack_1a6,bStack_1a5));
        local_1f8 = CONCAT17((char)uStack_1a4,
                             CONCAT16((char)((uint)uStack_1a4 >> 8),
                                      CONCAT15((char)((uint)uStack_1a4 >> 0x10),
                                               CONCAT14((char)((uint)uStack_1a4 >> 0x18),
                                                        CONCAT13(local_1a8,(undefined3)local_1f8))))
                            );
        local_1f0._0_3_ =
             CONCAT12((char)((uint)local_1a0 >> 8),
                      CONCAT11((char)((uint)local_1a0 >> 0x10),(char)((uint)local_1a0 >> 0x18)));
        local_1f0 = CONCAT17((char)local_19c,
                             CONCAT16((char)((uint)local_19c >> 8),
                                      CONCAT15((char)((uint)local_19c >> 0x10),
                                               CONCAT14((char)((uint)local_19c >> 0x18),
                                                        CONCAT13((char)local_1a0,
                                                                 (undefined3)local_1f0)))));
        local_1e8 = (code *)CONCAT53(CONCAT41(local_1e8._4_4_,(char)local_198),
                                     CONCAT12((char)((uint)local_198 >> 8),
                                              CONCAT11((char)((uint)local_198 >> 0x10),
                                                       (char)((uint)local_198 >> 0x18))));
      }
      else {
        local_194 = 0;
        lVar35 = 0;
        puVar37 = puVar5;
        while( true ) {
          iVar12 = (int)lVar35 + 1;
          local_14c = iVar12;
          *(char *)((long)&local_190 + lVar35 + 4) = (char)*puVar37;
          local_194 = local_194 + 8;
          if (local_194 == 0) {
            iVar31 = (int)local_190 + 1;
            local_190 = (code *)CONCAT44(local_190._4_4_,iVar31);
            if (iVar31 == 0) {
              local_144 = 1;
            }
          }
          if (iVar12 == 0x40) {
            FUN_0010d620(&local_1a8);
          }
          if (puVar37 == (uint *)((ulong)((int)lVar24 + 0x23) + (long)puVar5)) break;
          if (local_144 != 0) goto LAB_00113799;
          puVar37 = (uint *)((long)puVar37 + 1);
          lVar35 = (long)local_14c;
        }
        if (local_144 == 0) {
          if (local_148 == 0) goto LAB_001135da;
          goto LAB_001136c1;
        }
LAB_00113799:
        local_1f8 = 0;
        local_1f0 = 0;
        uVar14 = 0;
        local_1e8 = (code *)((ulong)local_1e8._4_4_ << 0x20);
      }
      pcVar17 = local_1d8;
      iVar12 = 0;
      do {
        local_1a8 = (string)0x0;
        bStack_1a7 = 0;
        bStack_1a6 = 0;
        bStack_1a5 = 0;
        if (iVar12 + 1 == 0x14) {
          iVar31 = 0x14;
          sVar23 = 0x10;
          iVar12 = 1;
        }
        else {
          iVar31 = iVar12 + 2;
          uVar14 = (uint)*(byte *)((long)&local_1f8 + (long)(iVar12 + 1)) | uVar14 << 8;
          if (iVar31 < 0x14) {
            lVar24 = (long)iVar31;
            iVar31 = iVar12 + 3;
            iVar12 = 3;
            uVar14 = uVar14 << 8 | (uint)*(byte *)((long)&local_1f8 + lVar24);
            sVar23 = 0;
          }
          else {
            iVar12 = 2;
            sVar23 = 8;
          }
        }
        uVar14 = uVar14 << sVar23;
        local_1a8 = (string)((byte)((int)uVar14 >> 0x12) & 0x3f);
        *pcVar17 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                   [(char)local_1a8];
        bStack_1a7 = (byte)((int)uVar14 >> 0xc) & 0x3f;
        pcVar17[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                     [(char)bStack_1a7];
        if (iVar12 == 1) {
          pcVar17[2] = '=';
LAB_001138ad:
          uVar14 = 0x40;
        }
        else {
          bStack_1a6 = (byte)((int)uVar14 >> 6) & 0x3f;
          pcVar17[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                       [(char)bStack_1a6];
          if (iVar12 != 3) goto LAB_001138ad;
          uVar14 = uVar14 & 0x3f;
        }
        pcVar17[3] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="
                     [(int)uVar14];
        if (0x13 < iVar31) goto LAB_001138c0;
        uVar14 = (uint)*(byte *)((long)&local_1f8 + (long)iVar31);
        pcVar17 = pcVar17 + 4;
        iVar12 = iVar31;
      } while( true );
    }
  }
  local_1d8[0] = '\0';
LAB_00112bf9:
  puVar11 = PTR__S_empty_rep_storage_00324fa0;
  puVar18 = *(undefined8 **)(*param_1 + 0x40);
  pcVar17 = (char *)*puVar18;
  uVar26 = puVar18[1] - (long)pcVar17;
  bVar38 = uVar26 == 5;
  if (5 < uVar26) {
    lVar24 = 5;
    pcVar28 = pcVar17;
    pcVar32 = "GET /";
    do {
      if (lVar24 == 0) break;
      lVar24 = lVar24 + -1;
      bVar38 = *pcVar28 == *pcVar32;
      pcVar28 = pcVar28 + (ulong)bVar39 * -2 + 1;
      pcVar32 = pcVar32 + (ulong)bVar39 * -2 + 1;
    } while (bVar38);
    if ((bVar38) && (pcVar17[5] != '/')) {
      local_208[0] = PTR__S_empty_rep_storage_00324fa0 + 0x18;
      if ((5 < (int)uVar26) &&
         (((cVar33 = pcVar17[5], cVar33 != ' ' && (cVar33 != '\r')) && (cVar33 != '\n')))) {
        uVar29 = 0;
        while( true ) {
          lVar24 = *(long *)(local_208[0] + -0x18);
          uVar2 = lVar24 + 1;
          if ((*(ulong *)(local_208[0] + -0x10) < uVar2) || (0 < *(int *)(local_208[0] + -8))) {
            std::string::reserve((ulong)local_208);
            lVar24 = *(long *)(local_208[0] + -0x18);
          }
          local_208[0][lVar24] = cVar33;
          if (local_208[0] + -0x18 != puVar11) {
            *(undefined4 *)(local_208[0] + -8) = 0;
            *(ulong *)(local_208[0] + -0x18) = uVar2;
            local_208[0][uVar2] = 0;
          }
          if (uVar29 == (int)uVar26 - 6) goto LAB_00112e83;
          cVar6 = *(char *)(**(long **)(*param_1 + 0x40) + 6 + uVar29);
          if ((cVar6 == '.') && (cVar33 == '.')) break;
          if (((cVar6 == '\r') || (cVar6 == ' ')) ||
             (uVar29 = uVar29 + 1, cVar33 = cVar6, cVar6 == '\n')) goto LAB_00112e83;
        }
        std::string::assign((char *)local_208,0x11f6d0);
      }
LAB_00112e83:
      pcVar17 = operator_new(0x18);
      pcVar17[0] = '\0';
      pcVar17[1] = '\0';
      pcVar17[2] = '\0';
      pcVar17[3] = '\0';
      pcVar17[4] = '\0';
      pcVar17[5] = '\0';
      pcVar17[6] = '\0';
      pcVar17[7] = '\0';
      pcVar17[8] = '\0';
      pcVar17[9] = '\0';
      pcVar17[10] = '\0';
      pcVar17[0xb] = '\0';
      pcVar17[0xc] = '\0';
      pcVar17[0xd] = '\0';
      pcVar17[0xe] = '\0';
      pcVar17[0xf] = '\0';
      pcVar17[0x10] = '\0';
      pcVar17[0x11] = '\0';
      pcVar17[0x12] = '\0';
      pcVar17[0x13] = '\0';
      pcVar17[0x14] = '\0';
      pcVar17[0x15] = '\0';
      pcVar17[0x16] = '\0';
      pcVar17[0x17] = '\0';
      Buffer::appendf(pcVar17,"HTTP/1.0 200 OK\r\n\r\n");
      std::string::string(&local_1a8,(string *)local_208);
      local_190 = (code *)0x0;
      if ((code *)param_1[7] != (code *)0x0) {
        (*(code *)param_1[7])(&local_1a0,param_1 + 5,2);
        local_188 = param_1[8];
        local_190 = (code *)param_1[7];
      }
      lVar24 = *(long *)(*param_1 + 0x38);
      if (*(char *)(lVar24 + 0x5a) != '\0') {
        fwrite("send(): send_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
        print_stack();
      }
      puVar18 = *(undefined8 **)(lVar24 + 0x60);
      *(undefined1 *)(lVar24 + 0x5a) = 1;
      *(char **)(lVar24 + 0x60) = pcVar17;
      if (puVar18 != (undefined8 *)0x0) {
        if ((void *)*puVar18 != (void *)0x0) {
          operator_delete((void *)*puVar18);
        }
        operator_delete(puVar18);
      }
      std::string::string((string *)(auStack_13b + 3),&local_1a8);
      auStack_120 = (undefined1  [8])0x0;
      if (local_190 != (code *)0x0) {
        (*local_190)(auStack_133 + 3,&local_1a0,2);
        local_118 = local_188;
        auStack_120 = (undefined1  [8])local_190;
      }
      local_1e8 = (code *)0x0;
      puVar18 = operator_new(0x28);
      *puVar18 = stack0xfffffffffffffec8;
      unique0x00008e00 = puVar11 + 0x18;
      puVar18[3] = 0;
      if (auStack_120 != (undefined1  [8])0x0) {
        (*(code *)auStack_120)(puVar18 + 1,auStack_133 + 3,2);
        puVar18[4] = local_118;
        puVar18[3] = auStack_120;
      }
      local_1f8 = *(undefined8 *)(lVar24 + 0x68);
      uVar7 = *(undefined8 *)(lVar24 + 0x70);
      local_1e8 = *(code **)(lVar24 + 0x78);
      *(undefined8 *)(lVar24 + 0x70) = local_1f0;
      *(undefined8 **)(lVar24 + 0x68) = puVar18;
      local_1e0 = *(undefined8 *)(lVar24 + 0x80);
      *(code **)(lVar24 + 0x78) = FUN_0010e040;
      *(code **)(lVar24 + 0x80) = FUN_0010dda0;
      local_1f0 = uVar7;
      if (local_1e8 != (code *)0x0) {
        (*local_1e8)(&local_1f8,&local_1f8,3);
      }
      if (auStack_120 != (undefined1  [8])0x0) {
        (*(code *)auStack_120)(auStack_133 + 3,auStack_133 + 3,3);
      }
      if ((allocator *)(stack0xfffffffffffffec8 + -0x18) != (allocator *)puVar11) {
        piVar3 = (int *)(stack0xfffffffffffffec8 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
          iVar12 = *(int *)(stack0xfffffffffffffec8 + -8);
          *(int *)(stack0xfffffffffffffec8 + -8) = iVar12 + -1;
        }
        else {
          LOCK();
          iVar12 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        if (iVar12 < 1) {
          std::string::_Rep::_M_destroy((allocator *)(stack0xfffffffffffffec8 + -0x18));
        }
      }
      cVar33 = *(char *)(lVar24 + 0x5a);
      local_218[0] = *(int *)(lVar24 + 0x40);
      lVar24 = *(long *)(lVar24 + 0x38);
      p_Var36 = *(_Rb_tree_node_base **)(lVar24 + 0x18);
      p_Var21 = (_Rb_tree_node_base *)(lVar24 + 0x10);
      p_Var22 = p_Var36;
      p_Var30 = p_Var21;
      if (p_Var36 == (_Rb_tree_node_base *)0x0) {
LAB_00113e70:
        lVar35 = 0;
        uVar14 = 0;
      }
      else {
        do {
          while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < local_218[0]) {
            p_Var1 = p_Var25 + 0x18;
            p_Var22 = *(_Rb_tree_node_base **)p_Var1;
            p_Var25 = p_Var30;
            if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_001130f2;
          }
          p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
          p_Var30 = p_Var25;
        } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_001130f2:
        if ((p_Var21 == p_Var25) || (p_Var22 = p_Var21, local_218[0] < *(int *)(p_Var25 + 0x20)))
        goto LAB_00113e70;
        do {
          while (p_Var30 = p_Var36, *(int *)(p_Var30 + 0x20) < local_218[0]) {
            p_Var25 = p_Var30 + 0x18;
            p_Var36 = *(_Rb_tree_node_base **)p_Var25;
            p_Var30 = p_Var22;
            if (*(_Rb_tree_node_base **)p_Var25 == (_Rb_tree_node_base *)0x0) goto LAB_0011312a;
          }
          p_Var36 = *(_Rb_tree_node_base **)(p_Var30 + 0x10);
          p_Var22 = p_Var30;
        } while (*(_Rb_tree_node_base **)(p_Var30 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011312a:
        if ((p_Var21 == p_Var30) || (local_218[0] < *(int *)(p_Var30 + 0x20))) {
          p_Var36 = operator_new(0x28);
          if (p_Var36 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var36 = 0;
            *(undefined8 *)(p_Var36 + 8) = 0;
            *(undefined8 *)(p_Var36 + 0x10) = 0;
            *(undefined8 *)(p_Var36 + 0x18) = 0;
            *(undefined4 *)(p_Var36 + 0x24) = 0;
            *(int *)(p_Var36 + 0x20) = local_218[0];
          }
          auVar40 = std::
                    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                    ::_M_get_insert_hint_unique_pos
                              ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                                *)(lVar24 + 8),p_Var30,p_Var36 + 0x20);
          p_Var22 = auVar40._8_8_;
          p_Var30 = auVar40._0_8_;
          if (p_Var22 == (_Rb_tree_node_base *)0x0) {
            operator_delete(p_Var36);
          }
          else {
            bVar38 = true;
            if ((p_Var30 == (_Rb_tree_node_base *)0x0) && (p_Var21 != p_Var22)) {
              bVar38 = *(int *)(p_Var36 + 0x20) < *(int *)(p_Var22 + 0x20);
            }
            std::_Rb_tree_insert_and_rebalance(bVar38,p_Var36,p_Var22,p_Var21);
            *(long *)(lVar24 + 0x30) = *(long *)(lVar24 + 0x30) + 1;
            p_Var30 = p_Var36;
          }
        }
        uVar14 = *(uint *)(p_Var30 + 0x24);
        lVar35 = 1;
      }
      lVar24 = lVar24 + (lVar35 + 1) * 0x30;
      p_Var4 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                *)(lVar24 + 8);
      p_Var21 = *(_Rb_tree_node_base **)(lVar24 + 0x18);
      p_Var30 = (_Rb_tree_node_base *)(lVar24 + 0x10);
      p_Var36 = p_Var21;
      p_Var22 = p_Var30;
      uVar13 = uVar14;
      if (p_Var21 != (_Rb_tree_node_base *)0x0) {
        do {
          while (p_Var25 = p_Var36, *(int *)(p_Var25 + 0x20) < local_218[0]) {
            p_Var1 = p_Var25 + 0x18;
            p_Var36 = *(_Rb_tree_node_base **)p_Var1;
            p_Var25 = p_Var22;
            if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00113212;
          }
          p_Var36 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
          p_Var22 = p_Var25;
        } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00113212:
        if ((p_Var30 != p_Var25) && (p_Var36 = p_Var30, *(int *)(p_Var25 + 0x20) <= local_218[0])) {
          do {
            while (p_Var22 = p_Var21, *(int *)(p_Var22 + 0x20) < local_218[0]) {
              p_Var25 = p_Var22 + 0x18;
              p_Var21 = *(_Rb_tree_node_base **)p_Var25;
              p_Var22 = p_Var36;
              if (*(_Rb_tree_node_base **)p_Var25 == (_Rb_tree_node_base *)0x0) goto LAB_0011324a;
            }
            p_Var21 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
            p_Var36 = p_Var22;
          } while (*(_Rb_tree_node_base **)(p_Var22 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011324a:
          if ((p_Var30 == p_Var22) || (local_218[0] < *(int *)(p_Var22 + 0x20))) {
            p_Var21 = operator_new(0x28);
            if (p_Var21 != (_Rb_tree_node_base *)0x0) {
              *(undefined4 *)p_Var21 = 0;
              *(undefined8 *)(p_Var21 + 8) = 0;
              *(undefined8 *)(p_Var21 + 0x10) = 0;
              *(undefined8 *)(p_Var21 + 0x18) = 0;
              *(undefined4 *)(p_Var21 + 0x24) = 0;
              *(int *)(p_Var21 + 0x20) = local_218[0];
            }
            auVar40 = std::
                      _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                      ::_M_get_insert_hint_unique_pos(p_Var4,p_Var22,p_Var21 + 0x20);
            p_Var36 = auVar40._8_8_;
            p_Var22 = auVar40._0_8_;
            if (p_Var36 == (_Rb_tree_node_base *)0x0) {
              operator_delete(p_Var21);
            }
            else {
              bVar38 = true;
              if ((p_Var22 == (_Rb_tree_node_base *)0x0) && (p_Var30 != p_Var36)) {
                bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var36 + 0x20);
              }
              std::_Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var36,p_Var30);
              *(long *)(lVar24 + 0x30) = *(long *)(lVar24 + 0x30) + 1;
              p_Var22 = p_Var21;
            }
          }
          uVar13 = *(uint *)(p_Var22 + 0x24);
        }
      }
      uVar34 = uVar13 | 2;
      if (cVar33 == '\0') {
        uVar34 = uVar13 & 0xfffffffd;
      }
      if (uVar14 == uVar34) {
        std::
        _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
        ::erase(p_Var4,local_218);
        goto LAB_001133cf;
      }
      p_Var21 = *(_Rb_tree_node_base **)(lVar24 + 0x18);
      p_Var22 = p_Var30;
      p_Var36 = p_Var30;
      if (*(_Rb_tree_node_base **)(lVar24 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_00113339:
        p_Var21 = operator_new(0x28);
        if (p_Var21 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var21 = 0;
          *(undefined8 *)(p_Var21 + 8) = 0;
          *(undefined8 *)(p_Var21 + 0x10) = 0;
          *(undefined8 *)(p_Var21 + 0x18) = 0;
          *(undefined4 *)(p_Var21 + 0x24) = 0;
          *(int *)(p_Var21 + 0x20) = local_218[0];
        }
        auVar40 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(p_Var4,p_Var36,p_Var21 + 0x20);
        p_Var22 = auVar40._8_8_;
        p_Var36 = auVar40._0_8_;
        if (p_Var22 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var21);
        }
        else {
          bVar38 = true;
          if ((p_Var36 == (_Rb_tree_node_base *)0x0) && (p_Var30 != p_Var22)) {
            bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var22 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var22,p_Var30);
          *(long *)(lVar24 + 0x30) = *(long *)(lVar24 + 0x30) + 1;
          p_Var36 = p_Var21;
        }
      }
      else {
        do {
          while (p_Var36 = p_Var21, *(int *)(p_Var36 + 0x20) < local_218[0]) {
            p_Var25 = p_Var36 + 0x18;
            p_Var21 = *(_Rb_tree_node_base **)p_Var25;
            p_Var36 = p_Var22;
            if (*(_Rb_tree_node_base **)p_Var25 == (_Rb_tree_node_base *)0x0) goto LAB_0011332a;
          }
          p_Var21 = *(_Rb_tree_node_base **)(p_Var36 + 0x10);
          p_Var22 = p_Var36;
        } while (*(_Rb_tree_node_base **)(p_Var36 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011332a:
        if ((p_Var30 == p_Var36) || (local_218[0] < *(int *)(p_Var36 + 0x20))) goto LAB_00113339;
      }
      *(uint *)(p_Var36 + 0x24) = uVar34;
LAB_001133cf:
      if (local_190 != (code *)0x0) {
        (*local_190)(&local_1a0,&local_1a0,3);
      }
      lVar24 = CONCAT44(uStack_1a4,
                        CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8))));
      if ((allocator *)(lVar24 + -0x18) != (allocator *)puVar11) {
        piVar3 = (int *)(lVar24 + -8);
        if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
          iVar12 = *(int *)(lVar24 + -8);
          *(int *)(lVar24 + -8) = iVar12 + -1;
        }
        else {
          LOCK();
          iVar12 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        if (iVar12 < 1) {
          std::string::_Rep::_M_destroy((allocator *)(lVar24 + -0x18));
        }
      }
      if ((allocator *)(local_208[0] + -0x18) == (allocator *)puVar11) {
        return;
      }
      piVar3 = (int *)(local_208[0] + -8);
      if (PTR___pthread_key_create_00324f80 == (undefined *)0x0) {
        iVar12 = *(int *)(local_208[0] + -8);
        *(int *)(local_208[0] + -8) = iVar12 + -1;
      }
      else {
        LOCK();
        iVar12 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
      }
      if (0 < iVar12) {
        return;
      }
      std::string::_Rep::_M_destroy((allocator *)(local_208[0] + -0x18));
      return;
    }
  }
  lVar24 = *(long *)(*param_1 + 0x38);
  if (*(char *)(lVar24 + 0x88) != '\0') {
    fwrite("recv(): recv_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
    print_stack();
  }
  *(undefined1 *)(lVar24 + 0x88) = 1;
  local_128 = (undefined1  [8])0x0;
  plVar16 = operator_new(8);
  *plVar16 = lVar24;
  puVar11 = PTR__M_manager_00324f68;
  unique0x00023d00 = *(undefined **)(lVar24 + 0x90);
  uVar7 = *(undefined8 *)(lVar24 + 0x98);
  local_128 = *(undefined1 (*) [8])(lVar24 + 0xa0);
  *(long **)(lVar24 + 0x90) = plVar16;
  *(undefined8 *)(lVar24 + 0x98) = stack0xfffffffffffffed0;
  *(undefined **)(lVar24 + 0xa0) = puVar11;
  auStack_120 = *(undefined1 (*) [8])(lVar24 + 0xa8);
  *(undefined **)(lVar24 + 0xa8) = PTR__M_invoke_00324f40;
  unique0x10001b43 = uVar7;
  if (local_128 != (undefined1  [8])0x0) {
    (*(code *)local_128)(auStack_13b + 3,auStack_13b + 3,3);
  }
  lVar35 = *(long *)(lVar24 + 0x38);
  iVar12 = *(int *)(lVar24 + 0x40);
  cVar33 = *(char *)(lVar24 + 0x88);
  p_Var36 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
  local_1f8 = CONCAT44(local_1f8._4_4_,iVar12);
  p_Var21 = (_Rb_tree_node_base *)(lVar35 + 0x10);
  p_Var22 = p_Var36;
  p_Var30 = p_Var21;
  if (p_Var36 == (_Rb_tree_node_base *)0x0) {
LAB_00114751:
    lVar20 = 0;
    uVar14 = 0;
  }
  else {
    do {
      while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < iVar12) {
        p_Var1 = p_Var25 + 0x18;
        p_Var22 = *(_Rb_tree_node_base **)p_Var1;
        p_Var25 = p_Var30;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00112d2b;
      }
      p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
      p_Var30 = p_Var25;
    } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00112d2b:
    if ((p_Var21 == p_Var25) || (p_Var22 = p_Var21, iVar12 < *(int *)(p_Var25 + 0x20)))
    goto LAB_00114751;
    do {
      if (*(int *)(p_Var36 + 0x20) < iVar12) {
        p_Var30 = *(_Rb_tree_node_base **)(p_Var36 + 0x18);
      }
      else {
        p_Var30 = *(_Rb_tree_node_base **)(p_Var36 + 0x10);
        p_Var22 = p_Var36;
      }
      p_Var36 = p_Var30;
    } while (p_Var30 != (_Rb_tree_node_base *)0x0);
    if ((p_Var21 == p_Var22) || (iVar12 < *(int *)(p_Var22 + 0x20))) {
      p_Var36 = operator_new(0x28);
      if (p_Var36 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var36 = 0;
        *(undefined8 *)(p_Var36 + 8) = 0;
        *(undefined8 *)(p_Var36 + 0x10) = 0;
        *(undefined8 *)(p_Var36 + 0x18) = 0;
        *(undefined4 *)(p_Var36 + 0x24) = 0;
        *(int *)(p_Var36 + 0x20) = (int)local_1f8;
      }
      auVar40 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(lVar35 + 8),p_Var22,p_Var36 + 0x20);
      p_Var30 = auVar40._8_8_;
      p_Var22 = auVar40._0_8_;
      if (p_Var30 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var36);
      }
      else {
        bVar38 = true;
        if ((p_Var22 == (_Rb_tree_node_base *)0x0) && (p_Var21 != p_Var30)) {
          bVar38 = *(int *)(p_Var36 + 0x20) < *(int *)(p_Var30 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar38,p_Var36,p_Var30,p_Var21);
        *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
        p_Var22 = p_Var36;
      }
    }
    uVar14 = *(uint *)(p_Var22 + 0x24);
    lVar20 = 1;
  }
  lVar35 = lVar35 + (lVar20 + 1) * 0x30;
  p_Var4 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
            *)(lVar35 + 8);
  p_Var21 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
  p_Var36 = (_Rb_tree_node_base *)(lVar35 + 0x10);
  uVar13 = uVar14;
  if (p_Var21 != (_Rb_tree_node_base *)0x0) {
    p_Var22 = p_Var21;
    p_Var30 = p_Var36;
    do {
      while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < (int)local_1f8) {
        p_Var1 = p_Var25 + 0x18;
        p_Var22 = *(_Rb_tree_node_base **)p_Var1;
        p_Var25 = p_Var30;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_0011402b;
      }
      p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
      p_Var30 = p_Var25;
    } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_0011402b:
    if ((p_Var36 != p_Var25) && (p_Var22 = p_Var36, *(int *)(p_Var25 + 0x20) <= (int)local_1f8)) {
      do {
        if (*(int *)(p_Var21 + 0x20) < (int)local_1f8) {
          p_Var30 = *(_Rb_tree_node_base **)(p_Var21 + 0x18);
        }
        else {
          p_Var30 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
          p_Var22 = p_Var21;
        }
        p_Var21 = p_Var30;
      } while (p_Var30 != (_Rb_tree_node_base *)0x0);
      if ((p_Var36 == p_Var22) || ((int)local_1f8 < *(int *)(p_Var22 + 0x20))) {
        p_Var21 = operator_new(0x28);
        if (p_Var21 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var21 = 0;
          *(undefined8 *)(p_Var21 + 8) = 0;
          *(undefined8 *)(p_Var21 + 0x10) = 0;
          *(undefined8 *)(p_Var21 + 0x18) = 0;
          *(undefined4 *)(p_Var21 + 0x24) = 0;
          *(int *)(p_Var21 + 0x20) = (int)local_1f8;
        }
        auVar40 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(p_Var4,p_Var22,p_Var21 + 0x20);
        p_Var30 = auVar40._8_8_;
        p_Var22 = auVar40._0_8_;
        if (p_Var30 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var21);
        }
        else {
          bVar38 = true;
          if ((p_Var22 == (_Rb_tree_node_base *)0x0) && (p_Var36 != p_Var30)) {
            bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var30 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var30,p_Var36);
          *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
          p_Var22 = p_Var21;
        }
      }
      uVar13 = *(uint *)(p_Var22 + 0x24);
    }
  }
  uVar34 = uVar13 | 1;
  if (cVar33 == '\0') {
    uVar34 = uVar13 & 0xfffffffe;
  }
  if (uVar14 == uVar34) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(p_Var4,(int *)&local_1f8);
  }
  else {
    p_Var21 = p_Var36;
    if (*(_Rb_tree_node_base **)(lVar35 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_0011434f:
      p_Var22 = operator_new(0x28);
      if (p_Var22 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var22 = 0;
        *(undefined8 *)(p_Var22 + 8) = 0;
        *(undefined8 *)(p_Var22 + 0x10) = 0;
        *(undefined8 *)(p_Var22 + 0x18) = 0;
        *(undefined4 *)(p_Var22 + 0x24) = 0;
        *(int *)(p_Var22 + 0x20) = (int)local_1f8;
      }
      auVar40 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos(p_Var4,p_Var21,p_Var22 + 0x20);
      p_Var30 = auVar40._8_8_;
      p_Var21 = auVar40._0_8_;
      if (p_Var30 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var22);
      }
      else {
        bVar38 = true;
        if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var36 != p_Var30)) {
          bVar38 = *(int *)(p_Var22 + 0x20) < *(int *)(p_Var30 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar38,p_Var22,p_Var30,p_Var36);
        *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
        p_Var21 = p_Var22;
      }
    }
    else {
      p_Var22 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
      do {
        if (*(int *)(p_Var22 + 0x20) < (int)local_1f8) {
          p_Var30 = *(_Rb_tree_node_base **)(p_Var22 + 0x18);
        }
        else {
          p_Var30 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
          p_Var21 = p_Var22;
        }
        p_Var22 = p_Var30;
      } while (p_Var30 != (_Rb_tree_node_base *)0x0);
      if ((p_Var36 == p_Var21) || ((int)local_1f8 < *(int *)(p_Var21 + 0x20))) goto LAB_0011434f;
    }
    *(uint *)(p_Var21 + 0x24) = uVar34;
  }
  if (*(char *)(lVar24 + 0x5a) != '\0') {
    fwrite("close(): send_flag != false\n",1,0x1c,*(FILE **)PTR_stderr_00324fb0);
    print_stack();
  }
  puVar18 = *(undefined8 **)(lVar24 + 0x60);
  *(undefined1 *)(lVar24 + 0x5a) = 1;
  *(undefined8 *)(lVar24 + 0x60) = 0;
  if (puVar18 != (undefined8 *)0x0) {
    if ((void *)*puVar18 != (void *)0x0) {
      operator_delete((void *)*puVar18);
    }
    operator_delete(puVar18);
  }
  local_128 = (undefined1  [8])0x0;
  pvVar15 = operator_new(1);
  puVar11 = PTR__M_manager_00324f78;
  unique0x00023d00 = *(undefined **)(lVar24 + 0x68);
  uVar7 = *(undefined8 *)(lVar24 + 0x70);
  local_128 = *(undefined1 (*) [8])(lVar24 + 0x78);
  *(void **)(lVar24 + 0x68) = pvVar15;
  *(undefined8 *)(lVar24 + 0x70) = stack0xfffffffffffffed0;
  *(undefined **)(lVar24 + 0x78) = puVar11;
  auStack_120 = *(undefined1 (*) [8])(lVar24 + 0x80);
  *(undefined **)(lVar24 + 0x80) = PTR__M_invoke_00324fe8;
  unique0x10001b3b = uVar7;
  if (local_128 != (undefined1  [8])0x0) {
    (*(code *)local_128)(auStack_13b + 3,auStack_13b + 3,3);
  }
  lVar35 = *(long *)(lVar24 + 0x38);
  iVar12 = *(int *)(lVar24 + 0x40);
  cVar33 = *(char *)(lVar24 + 0x5a);
  p_Var36 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
  local_1a8 = SUB41(iVar12,0);
  bStack_1a7 = (byte)((uint)iVar12 >> 8);
  bStack_1a6 = (byte)((uint)iVar12 >> 0x10);
  bStack_1a5 = (byte)((uint)iVar12 >> 0x18);
  p_Var21 = (_Rb_tree_node_base *)(lVar35 + 0x10);
  p_Var22 = p_Var36;
  p_Var30 = p_Var21;
  if (p_Var36 == (_Rb_tree_node_base *)0x0) {
LAB_00114747:
    lVar20 = 0;
    uVar14 = 0;
  }
  else {
    do {
      while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < iVar12) {
        p_Var1 = p_Var25 + 0x18;
        p_Var22 = *(_Rb_tree_node_base **)p_Var1;
        p_Var25 = p_Var30;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00114313;
      }
      p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
      p_Var30 = p_Var25;
    } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00114313:
    if ((p_Var25 == p_Var21) || (p_Var22 = p_Var21, iVar12 < *(int *)(p_Var25 + 0x20)))
    goto LAB_00114747;
    do {
      if (*(int *)(p_Var36 + 0x20) < iVar12) {
        p_Var30 = *(_Rb_tree_node_base **)(p_Var36 + 0x18);
      }
      else {
        p_Var30 = *(_Rb_tree_node_base **)(p_Var36 + 0x10);
        p_Var22 = p_Var36;
      }
      p_Var36 = p_Var30;
    } while (p_Var30 != (_Rb_tree_node_base *)0x0);
    if ((p_Var22 == p_Var21) || (iVar12 < *(int *)(p_Var22 + 0x20))) {
      p_Var36 = operator_new(0x28);
      if (p_Var36 != (_Rb_tree_node_base *)0x0) {
        *(undefined4 *)p_Var36 = 0;
        *(undefined8 *)(p_Var36 + 8) = 0;
        *(undefined8 *)(p_Var36 + 0x10) = 0;
        *(undefined8 *)(p_Var36 + 0x18) = 0;
        *(undefined4 *)(p_Var36 + 0x24) = 0;
        *(uint *)(p_Var36 + 0x20) =
             CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8)));
      }
      auVar40 = std::
                _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                ::_M_get_insert_hint_unique_pos
                          ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                            *)(lVar35 + 8),p_Var22,p_Var36 + 0x20);
      p_Var30 = auVar40._8_8_;
      p_Var22 = auVar40._0_8_;
      if (p_Var30 == (_Rb_tree_node_base *)0x0) {
        operator_delete(p_Var36);
      }
      else {
        bVar38 = true;
        if ((p_Var22 == (_Rb_tree_node_base *)0x0) && (p_Var21 != p_Var30)) {
          bVar38 = *(int *)(p_Var36 + 0x20) < *(int *)(p_Var30 + 0x20);
        }
        std::_Rb_tree_insert_and_rebalance(bVar38,p_Var36,p_Var30,p_Var21);
        *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
        p_Var22 = p_Var36;
      }
    }
    uVar14 = *(uint *)(p_Var22 + 0x24);
    lVar20 = 1;
  }
  lVar35 = lVar35 + (lVar20 + 1) * 0x30;
  p_Var4 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
            *)(lVar35 + 8);
  p_Var21 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
  p_Var36 = (_Rb_tree_node_base *)(lVar35 + 0x10);
  uVar13 = uVar14;
  if (p_Var21 != (_Rb_tree_node_base *)0x0) {
    iVar12 = CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8)));
    p_Var22 = p_Var21;
    p_Var30 = p_Var36;
    do {
      while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < iVar12) {
        p_Var1 = p_Var25 + 0x18;
        p_Var22 = *(_Rb_tree_node_base **)p_Var1;
        p_Var25 = p_Var30;
        if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00114443;
      }
      p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
      p_Var30 = p_Var25;
    } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00114443:
    if ((p_Var25 != p_Var36) && (p_Var22 = p_Var36, *(int *)(p_Var25 + 0x20) <= iVar12)) {
      do {
        if (*(int *)(p_Var21 + 0x20) < iVar12) {
          p_Var30 = *(_Rb_tree_node_base **)(p_Var21 + 0x18);
        }
        else {
          p_Var30 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
          p_Var22 = p_Var21;
        }
        p_Var21 = p_Var30;
      } while (p_Var30 != (_Rb_tree_node_base *)0x0);
      if ((p_Var22 == p_Var36) || (iVar12 < *(int *)(p_Var22 + 0x20))) {
        p_Var21 = operator_new(0x28);
        if (p_Var21 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var21 = 0;
          *(undefined8 *)(p_Var21 + 8) = 0;
          *(undefined8 *)(p_Var21 + 0x10) = 0;
          *(undefined8 *)(p_Var21 + 0x18) = 0;
          *(undefined4 *)(p_Var21 + 0x24) = 0;
          *(uint *)(p_Var21 + 0x20) =
               CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8)));
        }
        auVar40 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos(p_Var4,p_Var22,p_Var21 + 0x20);
        p_Var30 = auVar40._8_8_;
        p_Var22 = auVar40._0_8_;
        if (p_Var30 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var21);
        }
        else {
          bVar38 = true;
          if ((p_Var22 == (_Rb_tree_node_base *)0x0) && (p_Var36 != p_Var30)) {
            bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var30 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var30,p_Var36);
          *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
          p_Var22 = p_Var21;
        }
      }
      uVar13 = *(uint *)(p_Var22 + 0x24);
    }
  }
  uVar34 = uVar13 | 2;
  if (cVar33 == '\0') {
    uVar34 = uVar13 & 0xfffffffd;
  }
  if (uVar14 == uVar34) {
    std::
    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
    ::erase(p_Var4,(int *)&local_1a8);
    goto LAB_0011460d;
  }
  p_Var21 = p_Var36;
  if (*(_Rb_tree_node_base **)(lVar35 + 0x18) == (_Rb_tree_node_base *)0x0) {
LAB_001146c4:
    p_Var22 = operator_new(0x28);
    if (p_Var22 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var22 = 0;
      *(undefined8 *)(p_Var22 + 8) = 0;
      *(undefined8 *)(p_Var22 + 0x10) = 0;
      *(undefined8 *)(p_Var22 + 0x18) = 0;
      *(undefined4 *)(p_Var22 + 0x24) = 0;
      *(uint *)(p_Var22 + 0x20) =
           CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8)));
    }
    auVar40 = std::
              _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              ::_M_get_insert_hint_unique_pos(p_Var4,p_Var21,p_Var22 + 0x20);
    p_Var30 = auVar40._8_8_;
    p_Var21 = auVar40._0_8_;
    if (p_Var30 == (_Rb_tree_node_base *)0x0) {
      operator_delete(p_Var22);
    }
    else {
      bVar38 = true;
      if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var36 != p_Var30)) {
        bVar38 = *(int *)(p_Var22 + 0x20) < *(int *)(p_Var30 + 0x20);
      }
      std::_Rb_tree_insert_and_rebalance(bVar38,p_Var22,p_Var30,p_Var36);
      *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
      p_Var21 = p_Var22;
    }
  }
  else {
    iVar12 = CONCAT13(bStack_1a5,CONCAT12(bStack_1a6,CONCAT11(bStack_1a7,local_1a8)));
    p_Var22 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
    do {
      if (*(int *)(p_Var22 + 0x20) < iVar12) {
        p_Var30 = *(_Rb_tree_node_base **)(p_Var22 + 0x18);
      }
      else {
        p_Var30 = *(_Rb_tree_node_base **)(p_Var22 + 0x10);
        p_Var21 = p_Var22;
      }
      p_Var22 = p_Var30;
    } while (p_Var30 != (_Rb_tree_node_base *)0x0);
    if ((p_Var21 == p_Var36) || (iVar12 < *(int *)(p_Var21 + 0x20))) goto LAB_001146c4;
  }
  *(uint *)(p_Var21 + 0x24) = uVar34;
LAB_0011460d:
  local_128 = (undefined1  [8])0x0;
  pvVar15 = operator_new(1);
  puVar11 = PTR__M_manager_00324f58;
  unique0x00023d00 = *(undefined **)(lVar24 + 0xb0);
  uVar7 = *(undefined8 *)(lVar24 + 0xb8);
  local_128 = *(undefined1 (*) [8])(lVar24 + 0xc0);
  *(void **)(lVar24 + 0xb0) = pvVar15;
  *(undefined8 *)(lVar24 + 0xb8) = stack0xfffffffffffffed0;
  *(undefined **)(lVar24 + 0xc0) = puVar11;
  auStack_120 = *(undefined1 (*) [8])(lVar24 + 200);
  *(undefined **)(lVar24 + 200) = PTR__M_invoke_00324eb0;
  if (local_128 != (undefined1  [8])0x0) {
    unique0x10001b2b = uVar7;
    (*(code *)local_128)(auStack_13b + 3,auStack_13b + 3,3);
  }
  return;
LAB_001138c0:
  pcVar17[4] = '\0';
  if (local_1d8[0] != '\0') {
    lVar24 = *param_1;
    puVar18 = *(undefined8 **)(lVar24 + 0x40);
    pvVar15 = (void *)*puVar18;
    pvVar19 = memmem(pvVar15,puVar18[1] - (long)pvVar15,"permessage-deflate",0x12);
    if (pvVar19 != (void *)0x0) {
      *(undefined1 *)(lVar24 + 0x58) = 1;
      pvVar15 = operator_new(0x70);
      *(void **)(lVar24 + 0x60) = pvVar15;
      lVar24 = *param_1;
      pvVar15 = operator_new(0x70);
      *(void **)(lVar24 + 0x68) = pvVar15;
      puVar18 = *(undefined8 **)(*param_1 + 0x60);
      puVar8 = *(undefined8 **)(*param_1 + 0x68);
      puVar18[8] = 0;
      puVar18[9] = 0;
      puVar18[10] = 0;
      *(undefined4 *)(puVar18 + 1) = 0;
      *puVar18 = 0;
      iVar12 = inflateInit2_(puVar18,0xfffffff1,"1.2.7",0x70);
      if (iVar12 == 0) {
        puVar8[8] = 0;
        puVar8[9] = 0;
        puVar8[10] = 0;
        *(undefined4 *)(puVar8 + 1) = 0;
        *puVar8 = 0;
        iVar12 = deflateInit2_(puVar8,0xffffffff,8,0xfffffff1,8,0,"1.2.7",0x70);
        if (iVar12 != 0) {
          inflateEnd(puVar18);
          goto LAB_0011397b;
        }
      }
      else {
LAB_0011397b:
        lVar24 = *param_1;
        *(undefined1 *)(lVar24 + 0x58) = 0;
        operator_delete(*(void **)(lVar24 + 0x60));
        operator_delete(*(void **)(*param_1 + 0x68));
      }
      puVar18 = *(undefined8 **)(*param_1 + 0x40);
      pvVar15 = (void *)*puVar18;
    }
    pvVar19 = (void *)((long)(param_2 + 4) + (long)pvVar15);
    if (pvVar19 != pvVar15) {
      lVar24 = 0;
      if ((pvVar19 != (void *)puVar18[1]) && (__n = (long)puVar18[1] - (long)pvVar19, __n != 0)) {
        pvVar15 = memmove(pvVar15,pvVar19,__n);
        lVar24 = puVar18[1] - (long)pvVar19;
      }
      puVar18[1] = lVar24 + (long)pvVar15;
    }
    pcVar17 = operator_new(0x18);
    pcVar17[0] = '\0';
    pcVar17[1] = '\0';
    pcVar17[2] = '\0';
    pcVar17[3] = '\0';
    pcVar17[4] = '\0';
    pcVar17[5] = '\0';
    pcVar17[6] = '\0';
    pcVar17[7] = '\0';
    pcVar17[8] = '\0';
    pcVar17[9] = '\0';
    pcVar17[10] = '\0';
    pcVar17[0xb] = '\0';
    pcVar17[0xc] = '\0';
    pcVar17[0xd] = '\0';
    pcVar17[0xe] = '\0';
    pcVar17[0xf] = '\0';
    pcVar17[0x10] = '\0';
    pcVar17[0x11] = '\0';
    pcVar17[0x12] = '\0';
    pcVar17[0x13] = '\0';
    pcVar17[0x14] = '\0';
    pcVar17[0x15] = '\0';
    pcVar17[0x16] = '\0';
    pcVar17[0x17] = '\0';
    pcVar28 = "Sec-WebSocket-Extensions: permessage-deflate\r\n";
    if (*(char *)(*param_1 + 0x58) == '\0') {
      pcVar28 = "";
    }
    Buffer::appendf(pcVar17,
                    "HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: Upgrade\r\n%sSec-WebSocket-Accept: %s\r\n\r\n"
                    ,pcVar28,local_1d8);
    lVar24 = *(long *)(*param_1 + 0x38);
    if (*(char *)(lVar24 + 0x5a) != '\0') {
      fwrite("send(): send_flag != false\n",1,0x1b,*(FILE **)PTR_stderr_00324fb0);
      print_stack();
    }
    puVar18 = *(undefined8 **)(lVar24 + 0x60);
    *(undefined1 *)(lVar24 + 0x5a) = 1;
    *(char **)(lVar24 + 0x60) = pcVar17;
    if (puVar18 != (undefined8 *)0x0) {
      if ((void *)*puVar18 != (void *)0x0) {
        operator_delete((void *)*puVar18);
      }
      operator_delete(puVar18);
    }
    local_128 = (undefined1  [8])0x0;
    if ((code *)param_1[3] == (code *)0x0) {
      lVar35 = 0;
    }
    else {
      (*(code *)param_1[3])(puVar5,param_1 + 1,2);
      auStack_120 = (undefined1  [8])param_1[4];
      lVar35 = param_1[3];
    }
    uVar7 = *(undefined8 *)(lVar24 + 0x68);
    uVar9 = *(undefined8 *)(lVar24 + 0x70);
    local_128 = *(undefined1 (*) [8])(lVar24 + 0x78);
    *(undefined **)(lVar24 + 0x68) = stack0xfffffffffffffec8;
    *(undefined8 *)(lVar24 + 0x70) = stack0xfffffffffffffed0;
    uVar10 = *(undefined8 *)(lVar24 + 0x80);
    *(long *)(lVar24 + 0x78) = lVar35;
    *(undefined1 (*) [8])(lVar24 + 0x80) = auStack_120;
    unique0x10001b0b = (undefined *)uVar7;
    unique0x10001b33 = uVar9;
    auStack_120 = (undefined1  [8])uVar10;
    if (local_128 != (undefined1  [8])0x0) {
      (*(code *)local_128)(puVar5,puVar5,3);
    }
    lVar35 = *(long *)(lVar24 + 0x38);
    iVar12 = *(int *)(lVar24 + 0x40);
    cVar33 = *(char *)(lVar24 + 0x5a);
    p_Var36 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
    stack0xfffffffffffffec8 = (undefined *)CONCAT44(stack0xfffffffffffffecc,iVar12);
    p_Var21 = (_Rb_tree_node_base *)(lVar35 + 0x10);
    p_Var22 = p_Var36;
    p_Var30 = p_Var21;
    if (p_Var36 == (_Rb_tree_node_base *)0x0) {
LAB_00113e40:
      lVar24 = 0;
      uVar14 = 0;
    }
    else {
      do {
        while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < iVar12) {
          p_Var1 = p_Var25 + 0x18;
          p_Var22 = *(_Rb_tree_node_base **)p_Var1;
          p_Var25 = p_Var30;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00113b4b;
        }
        p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
        p_Var30 = p_Var25;
      } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00113b4b:
      if ((p_Var21 == p_Var25) || (p_Var22 = p_Var21, iVar12 < *(int *)(p_Var25 + 0x20)))
      goto LAB_00113e40;
      do {
        while (p_Var30 = p_Var36, *(int *)(p_Var30 + 0x20) < iVar12) {
          p_Var25 = p_Var30 + 0x18;
          p_Var36 = *(_Rb_tree_node_base **)p_Var25;
          p_Var30 = p_Var22;
          if (*(_Rb_tree_node_base **)p_Var25 == (_Rb_tree_node_base *)0x0) goto LAB_00113b83;
        }
        p_Var36 = *(_Rb_tree_node_base **)(p_Var30 + 0x10);
        p_Var22 = p_Var30;
      } while (*(_Rb_tree_node_base **)(p_Var30 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00113b83:
      if ((p_Var21 == p_Var30) || (iVar12 < *(int *)(p_Var30 + 0x20))) {
        p_Var36 = operator_new(0x28);
        if (p_Var36 != (_Rb_tree_node_base *)0x0) {
          *(undefined4 *)p_Var36 = 0;
          *(undefined8 *)(p_Var36 + 8) = 0;
          *(undefined8 *)(p_Var36 + 0x10) = 0;
          *(undefined8 *)(p_Var36 + 0x18) = 0;
          *(undefined4 *)(p_Var36 + 0x24) = 0;
          *(undefined4 *)(p_Var36 + 0x20) = auStack_13b._3_4_;
        }
        auVar40 = std::
                  _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                  ::_M_get_insert_hint_unique_pos
                            ((_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                              *)(lVar35 + 8),p_Var30,p_Var36 + 0x20);
        p_Var22 = auVar40._8_8_;
        p_Var30 = auVar40._0_8_;
        if (p_Var22 == (_Rb_tree_node_base *)0x0) {
          operator_delete(p_Var36);
        }
        else {
          bVar38 = true;
          if ((p_Var30 == (_Rb_tree_node_base *)0x0) && (p_Var21 != p_Var22)) {
            bVar38 = *(int *)(p_Var36 + 0x20) < *(int *)(p_Var22 + 0x20);
          }
          std::_Rb_tree_insert_and_rebalance(bVar38,p_Var36,p_Var22,p_Var21);
          *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
          p_Var30 = p_Var36;
        }
      }
      uVar14 = *(uint *)(p_Var30 + 0x24);
      lVar24 = 1;
    }
    lVar35 = lVar35 + (lVar24 + 1) * 0x30;
    p_Var4 = (_Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              *)(lVar35 + 8);
    p_Var21 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
    p_Var36 = (_Rb_tree_node_base *)(lVar35 + 0x10);
    uVar13 = uVar14;
    if (p_Var21 != (_Rb_tree_node_base *)0x0) {
      p_Var22 = p_Var21;
      p_Var30 = p_Var36;
      do {
        while (p_Var25 = p_Var22, *(int *)(p_Var25 + 0x20) < (int)auStack_13b._3_4_) {
          p_Var1 = p_Var25 + 0x18;
          p_Var22 = *(_Rb_tree_node_base **)p_Var1;
          p_Var25 = p_Var30;
          if (*(_Rb_tree_node_base **)p_Var1 == (_Rb_tree_node_base *)0x0) goto LAB_00113c6b;
        }
        p_Var22 = *(_Rb_tree_node_base **)(p_Var25 + 0x10);
        p_Var30 = p_Var25;
      } while (*(_Rb_tree_node_base **)(p_Var25 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00113c6b:
      if ((p_Var36 != p_Var25) &&
         (p_Var22 = p_Var36, *(int *)(p_Var25 + 0x20) <= (int)auStack_13b._3_4_)) {
        do {
          while (p_Var30 = p_Var21, *(int *)(p_Var30 + 0x20) < (int)auStack_13b._3_4_) {
            p_Var25 = p_Var30 + 0x18;
            p_Var21 = *(_Rb_tree_node_base **)p_Var25;
            p_Var30 = p_Var22;
            if (*(_Rb_tree_node_base **)p_Var25 == (_Rb_tree_node_base *)0x0) goto LAB_00113ca3;
          }
          p_Var21 = *(_Rb_tree_node_base **)(p_Var30 + 0x10);
          p_Var22 = p_Var30;
        } while (*(_Rb_tree_node_base **)(p_Var30 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00113ca3:
        if ((p_Var36 == p_Var30) || ((int)auStack_13b._3_4_ < *(int *)(p_Var30 + 0x20))) {
          p_Var21 = operator_new(0x28);
          if (p_Var21 != (_Rb_tree_node_base *)0x0) {
            *(undefined4 *)p_Var21 = 0;
            *(undefined8 *)(p_Var21 + 8) = 0;
            *(undefined8 *)(p_Var21 + 0x10) = 0;
            *(undefined8 *)(p_Var21 + 0x18) = 0;
            *(undefined4 *)(p_Var21 + 0x24) = 0;
            *(undefined4 *)(p_Var21 + 0x20) = auStack_13b._3_4_;
          }
          auVar40 = std::
                    _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
                    ::_M_get_insert_hint_unique_pos(p_Var4,p_Var30,p_Var21 + 0x20);
          p_Var22 = auVar40._8_8_;
          p_Var30 = auVar40._0_8_;
          if (p_Var22 == (_Rb_tree_node_base *)0x0) {
            operator_delete(p_Var21);
          }
          else {
            bVar38 = true;
            if ((p_Var30 == (_Rb_tree_node_base *)0x0) && (p_Var36 != p_Var22)) {
              bVar38 = *(int *)(p_Var21 + 0x20) < *(int *)(p_Var22 + 0x20);
            }
            std::_Rb_tree_insert_and_rebalance(bVar38,p_Var21,p_Var22,p_Var36);
            *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
            p_Var30 = p_Var21;
          }
        }
        uVar13 = *(uint *)(p_Var30 + 0x24);
      }
    }
    uVar34 = uVar13 | 2;
    if (cVar33 == '\0') {
      uVar34 = uVar13 & 0xfffffffd;
    }
    if (uVar14 == uVar34) {
      std::
      _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
      ::erase(p_Var4,(int *)puVar5);
      return;
    }
    p_Var21 = p_Var36;
    if (*(_Rb_tree_node_base **)(lVar35 + 0x18) != (_Rb_tree_node_base *)0x0) {
      p_Var22 = *(_Rb_tree_node_base **)(lVar35 + 0x18);
      p_Var30 = p_Var36;
      do {
        while (p_Var21 = p_Var22, *(int *)(p_Var21 + 0x20) < (int)auStack_13b._3_4_) {
          p_Var25 = p_Var21 + 0x18;
          p_Var22 = *(_Rb_tree_node_base **)p_Var25;
          p_Var21 = p_Var30;
          if (*(_Rb_tree_node_base **)p_Var25 == (_Rb_tree_node_base *)0x0) goto LAB_00113d82;
        }
        p_Var22 = *(_Rb_tree_node_base **)(p_Var21 + 0x10);
        p_Var30 = p_Var21;
      } while (*(_Rb_tree_node_base **)(p_Var21 + 0x10) != (_Rb_tree_node_base *)0x0);
LAB_00113d82:
      if ((p_Var36 != p_Var21) && (*(int *)(p_Var21 + 0x20) <= (int)auStack_13b._3_4_))
      goto LAB_00113e28;
    }
    p_Var22 = operator_new(0x28);
    if (p_Var22 != (_Rb_tree_node_base *)0x0) {
      *(undefined4 *)p_Var22 = 0;
      *(undefined8 *)(p_Var22 + 8) = 0;
      *(undefined8 *)(p_Var22 + 0x10) = 0;
      *(undefined8 *)(p_Var22 + 0x18) = 0;
      *(undefined4 *)(p_Var22 + 0x24) = 0;
      *(undefined4 *)(p_Var22 + 0x20) = auStack_13b._3_4_;
    }
    auVar40 = std::
              _Rb_tree<int,std::pair<int_const,int>,std::_Select1st<std::pair<int_const,int>>,std::less<int>,std::allocator<std::pair<int_const,int>>>
              ::_M_get_insert_hint_unique_pos(p_Var4,p_Var21,p_Var22 + 0x20);
    p_Var30 = auVar40._8_8_;
    p_Var21 = auVar40._0_8_;
    if (p_Var30 == (_Rb_tree_node_base *)0x0) {
      operator_delete(p_Var22);
    }
    else {
      bVar38 = true;
      if ((p_Var21 == (_Rb_tree_node_base *)0x0) && (p_Var36 != p_Var30)) {
        bVar38 = *(int *)(p_Var22 + 0x20) < *(int *)(p_Var30 + 0x20);
      }
      std::_Rb_tree_insert_and_rebalance(bVar38,p_Var22,p_Var30,p_Var36);
      *(long *)(lVar35 + 0x30) = *(long *)(lVar35 + 0x30) + 1;
      p_Var21 = p_Var22;
    }
LAB_00113e28:
    *(uint *)(p_Var21 + 0x24) = uVar34;
    return;
  }
  goto LAB_00112bf9;
}



