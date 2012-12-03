// -*- C++ -*-
/*!
 * @file crc.h
 * @brief CRC calculation functions
 * @date $Date$
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2010
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id$
 *
 */

#ifndef COIL_CRC_H
#define COIL_CRC_H

#include <sys/types.h>

namespace coil
{
  /*
   * @if jp
   *
   * @brief CRC-16 �v�Z�֐�
   *
   * CRC���: CRC-CCITT
   * CRC������:  x^16 + x^12 + x^5 + 1 (0x1021)
   * �����l:  0xFFFF
   * �o��XOR: 0x0000
   * ���̓r�b�g���]: �Ȃ�
   * �o�̓r�b�g���]: �Ȃ�
   * �r�b�g�V�t�g: ��
   *
   * @param str �f�[�^�X�g���[��
   * @param len �f�[�^��
   *
   * @return �v�Z����
   *
   * @else
   *
   * @brief CRC-16 calculation function
   *
   * CRC type: CRC-CCITT
   * CRC generator polynomial:  x^16 + x^12 + x^5 + 1 (0x1021)
   * Initial value: 0xFFFF
   * Output XOR: 0x0000
   * Input bit inversion: None
   * Output bit inversion: None
   * Bit shift: left
   *
   * @param str Data stream
   * @param len Data length
   *
   * @return Result calculation
   *
   * @endif
   */
  unsigned short crc16(const char* str, size_t len);
  
  /*!
   * @if jp
   *
   * @brief CRC-32 �v�Z�֐�
   *
   * CRC���: RFC2083 Appendix 15
   * CRC������:  0xedb88320L
   * �����l:  0xFFFFFFFF
   * �o��XOR: 0xFFFFFFFF
   * ���̓r�b�g���]: �Ȃ�
   * �o�̓r�b�g���]: �Ȃ�
   * �r�b�g�V�t�g: �E
   *
   * @param str �f�[�^�X�g���[��
   * @param len �f�[�^��
   *
   * @return �v�Z����
   *
   * @else
   *
   * @brief CRC-32 calculation function
   * 
   * CRC type: RFC2083 Appendix 15
   *          http://www.faqs.org/rfcs/rfc2083.html
   *          http://www.efg2.com/Lab/Mathematics/CRC.htm
   * CRC polynomial:  0xedb88320L
   * Initial value: 0xFFFFFFFF
   * Output XOR: 0xFFFFFFFF
   * Input bit inversion: None
   * Output bit inversion: None
   * Bit shift: right
   * 
   * @param str Data stream
   * @param len Data length
   *
   * @return Result calculation
   *
   * @endif
   */
  unsigned long crc32(const char* str, size_t len);
}; //namespace coil

#endif // COIL_CRC_H
