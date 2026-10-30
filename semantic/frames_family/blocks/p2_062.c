
/* WARNING: Switch with 1 destination removed at 0x00107240 */

void std::vector<unsigned_char,std::allocator<unsigned_char>>::
     _M_range_insert<__gnu_cxx::__normal_iterator<char*,std::string>>
               (long *param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  void *__dest;
  undefined1 *puVar4;
  ulong uVar5;
  size_t sVar6;
  long lVar7;
  size_t sVar8;
  void *__src;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  undefined1 *puVar12;
  ulong uVar13;
  undefined1 *unaff_R14;
  ulong uVar14;
  ulong uStack_48;
  
  if (param_3 == param_4) {
    return;
  }
  puVar12 = (undefined1 *)param_1[1];
  uVar9 = (long)param_4 - (long)param_3;
  if (uVar9 <= (ulong)(param_1[2] - (long)puVar12)) {
    uVar14 = (long)puVar12 - (long)param_2;
    if (uVar9 < uVar14) {
      puVar3 = puVar12 + -uVar9;
      puVar4 = puVar12;
      if ((long)puVar12 - (long)puVar3 != 0) {
        puVar4 = memmove(puVar12,puVar3,(long)puVar12 - (long)puVar3);
        puVar12 = (undefined1 *)param_1[1];
      }
      sVar8 = (long)puVar3 - (long)param_2;
      param_1[1] = (long)(puVar12 + uVar9);
      if (sVar8 != 0) {
        memmove(puVar4 + -sVar8,param_2,sVar8);
      }
      if ((long)uVar9 < 1) {
        return;
      }
      if ((param_2 < param_3 + 0x10 && param_3 < param_2 + 0x10) || (uVar9 < 0x10)) {
        uVar14 = 0;
        do {
          param_2[uVar14] = param_3[uVar14];
          uVar14 = uVar14 + 1;
        } while (uVar9 != uVar14);
        return;
      }
      lVar7 = 0;
      uVar10 = 0;
      uVar14 = uVar9 >> 4;
      uVar5 = uVar14 * 0x10;
      do {
        uVar2 = *(undefined8 *)((long)(param_3 + lVar7) + 8);
        uVar10 = uVar10 + 1;
        *(undefined8 *)(param_2 + lVar7) = *(undefined8 *)(param_3 + lVar7);
        *(undefined8 *)((long)(param_2 + lVar7) + 8) = uVar2;
        lVar7 = lVar7 + 0x10;
      } while (uVar10 < uVar14);
      lVar7 = uVar9 + uVar14 * -0x10;
      if (uVar9 == uVar5) {
        return;
      }
    }
    else {
      puVar4 = param_3 + uVar14;
      uVar5 = (long)param_4 - (long)puVar4;
      if (0 < (long)uVar5) {
        if ((puVar12 < puVar4 + 0x10 && puVar4 < puVar12 + 0x10) || (uVar5 < 0x10)) {
          puVar3 = puVar4;
          do {
            uVar1 = *puVar3;
            puVar3 = puVar3 + 1;
            *puVar12 = uVar1;
            puVar12 = puVar12 + 1;
          } while (puVar3 != puVar4 + uVar5);
        }
        else {
          lVar7 = 0;
          uVar13 = 0;
          uVar11 = uVar5 >> 4;
          uVar10 = uVar11 * 0x10;
          do {
            uVar2 = *(undefined8 *)((long)(puVar4 + lVar7) + 8);
            uVar13 = uVar13 + 1;
            *(undefined8 *)(puVar12 + lVar7) = *(undefined8 *)(puVar4 + lVar7);
            *(undefined8 *)((long)(puVar12 + lVar7) + 8) = uVar2;
            lVar7 = lVar7 + 0x10;
          } while (uVar13 < uVar11);
          puVar3 = puVar4 + uVar10;
          puVar12 = puVar12 + uVar10;
          lVar7 = uVar5 + uVar11 * -0x10;
          if (((((uVar5 != uVar10) && (*puVar12 = *puVar3, lVar7 != 1 && -1 < lVar7 + -1)) &&
               (puVar12[1] = puVar3[1], lVar7 != 2)) &&
              (((puVar12[2] = puVar3[2], lVar7 != 3 && (puVar12[3] = puVar3[3], lVar7 != 4)) &&
               ((puVar12[4] = puVar3[4], lVar7 != 5 &&
                ((puVar12[5] = puVar3[5], lVar7 != 6 && (puVar12[6] = puVar3[6], lVar7 != 7))))))))
             && (((puVar12[7] = puVar3[7], lVar7 != 8 &&
                  ((((puVar12[8] = puVar3[8], lVar7 != 9 && (puVar12[9] = puVar3[9], lVar7 != 10))
                    && (puVar12[10] = puVar3[10], lVar7 != 0xb)) &&
                   ((puVar12[0xb] = puVar3[0xb], lVar7 != 0xc &&
                    (puVar12[0xc] = puVar3[0xc], lVar7 != 0xd)))))) &&
                 (puVar12[0xd] = puVar3[0xd], lVar7 != 0xe)))) {
            puVar12[0xe] = puVar3[0xe];
          }
        }
        puVar12 = (undefined1 *)param_1[1];
      }
      puVar12 = puVar12 + (uVar9 - uVar14);
      param_1[1] = (long)puVar12;
      if (uVar14 != 0) {
        memmove(puVar12,param_2,uVar14);
        puVar12 = (undefined1 *)param_1[1];
      }
      uVar9 = (long)puVar4 - (long)param_3;
      param_1[1] = (long)(puVar12 + uVar14);
      if ((long)uVar9 < 1) {
        return;
      }
      if ((uVar9 < 0x10) || (param_3 < param_2 + 0x10 && param_2 < param_3 + 0x10)) {
        uVar14 = 0;
        do {
          param_2[uVar14] = param_3[uVar14];
          uVar14 = uVar14 + 1;
        } while (uVar14 != uVar9);
        return;
      }
      lVar7 = 0;
      uVar10 = 0;
      uVar14 = uVar9 >> 4;
      uVar5 = uVar14 * 0x10;
      do {
        uVar2 = *(undefined8 *)((long)(param_3 + lVar7) + 8);
        uVar10 = uVar10 + 1;
        *(undefined8 *)(param_2 + lVar7) = *(undefined8 *)(param_3 + lVar7);
        *(undefined8 *)((long)(param_2 + lVar7) + 8) = uVar2;
        lVar7 = lVar7 + 0x10;
      } while (uVar10 < uVar14);
      lVar7 = uVar9 + uVar14 * -0x10;
      if (uVar9 == uVar5) {
        return;
      }
    }
    param_2 = param_2 + uVar5;
    param_3 = param_3 + uVar5;
    *param_2 = *param_3;
    if ((((lVar7 != 1 && -1 < lVar7 + -1) && (param_2[1] = param_3[1], lVar7 != 2)) &&
        (param_2[2] = param_3[2], lVar7 != 3)) &&
       (((((param_2[3] = param_3[3], lVar7 != 4 && (param_2[4] = param_3[4], lVar7 != 5)) &&
          ((param_2[5] = param_3[5], lVar7 != 6 &&
           ((param_2[6] = param_3[6], lVar7 != 7 && (param_2[7] = param_3[7], lVar7 != 8)))))) &&
         (param_2[8] = param_3[8], lVar7 != 9)) &&
        ((((param_2[9] = param_3[9], lVar7 != 10 && (param_2[10] = param_3[10], lVar7 != 0xb)) &&
          (param_2[0xb] = param_3[0xb], lVar7 != 0xc)) &&
         ((param_2[0xc] = param_3[0xc], lVar7 != 0xd && (param_2[0xd] = param_3[0xd], lVar7 != 0xe))
         )))))) {
      param_2[0xe] = param_3[0xe];
      return;
    }
    return;
  }
  __src = (void *)*param_1;
  uVar14 = (long)puVar12 - (long)__src;
  if (~uVar14 < uVar9) {
    std::__throw_length_error("vector::_M_range_insert");
    uStack_48 = uVar14;
  }
  else {
    uVar5 = uVar9;
    if (uVar9 <= uVar14) {
      uVar5 = uVar14;
    }
    uStack_48 = 0xffffffffffffffff;
    unaff_R14 = param_3;
    if ((!CARRY8(uVar14,uVar5)) && (uStack_48 = uVar14 + uVar5, uVar14 + uVar5 == 0)) {
      uStack_48 = 0;
      __dest = (void *)0x0;
      goto LAB_0010d326;
    }
  }
  __dest = operator_new(uStack_48);
  __src = (void *)*param_1;
LAB_0010d326:
  sVar6 = (long)param_2 - (long)__src;
  sVar8 = 0;
  if (sVar6 != 0) {
    memmove(__dest,__src,sVar6);
    sVar8 = sVar6;
  }
  puVar12 = (undefined1 *)(sVar8 + (long)__dest);
  if (0 < (long)uVar9) {
    if ((param_3 < puVar12 + 0x10 && puVar12 < param_3 + 0x10) || (uVar9 < 0x10)) {
      puVar4 = puVar12;
      do {
        uVar1 = *unaff_R14;
        unaff_R14 = unaff_R14 + 1;
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      } while (unaff_R14 != param_3 + uVar9);
    }
    else {
      lVar7 = 0;
      uVar10 = 0;
      uVar5 = uVar9 >> 4;
      uVar14 = uVar5 * 0x10;
      do {
        uVar2 = *(undefined8 *)((long)(param_3 + lVar7) + 8);
        uVar10 = uVar10 + 1;
        *(undefined8 *)(puVar12 + lVar7) = *(undefined8 *)(param_3 + lVar7);
        *(undefined8 *)((long)(puVar12 + lVar7) + 8) = uVar2;
        lVar7 = lVar7 + 0x10;
      } while (uVar10 < uVar5);
      param_3 = param_3 + uVar14;
      puVar4 = puVar12 + uVar14;
      lVar7 = uVar9 + uVar5 * -0x10;
      if ((((((uVar9 != uVar14) && (*puVar4 = *param_3, 0 < lVar7 + -1)) &&
            (puVar4[1] = param_3[1], lVar7 != 2)) &&
           ((puVar4[2] = param_3[2], lVar7 != 3 && (puVar4[3] = param_3[3], lVar7 != 4)))) &&
          (puVar4[4] = param_3[4], lVar7 != 5)) &&
         ((((puVar4[5] = param_3[5], lVar7 != 6 && (puVar4[6] = param_3[6], lVar7 != 7)) &&
           ((puVar4[7] = param_3[7], lVar7 != 8 &&
            (((puVar4[8] = param_3[8], lVar7 != 9 && (puVar4[9] = param_3[9], lVar7 != 10)) &&
             (puVar4[10] = param_3[10], lVar7 != 0xb)))))) &&
          (((puVar4[0xb] = param_3[0xb], lVar7 != 0xc && (puVar4[0xc] = param_3[0xc], lVar7 != 0xd))
           && (puVar4[0xd] = param_3[0xd], lVar7 != 0xe)))))) {
        puVar4[0xe] = param_3[0xe];
      }
    }
    puVar12 = puVar12 + uVar9;
  }
  sVar6 = param_1[1] - (long)param_2;
  sVar8 = 0;
  if (sVar6 != 0) {
    puVar12 = memmove(puVar12,param_2,sVar6);
    sVar8 = sVar6;
  }
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
  }
  *param_1 = (long)__dest;
  param_1[1] = (long)(puVar12 + sVar8);
  param_1[2] = (long)__dest + uStack_48;
  return;
}



