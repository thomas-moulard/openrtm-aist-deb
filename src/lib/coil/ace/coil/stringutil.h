// -*- C++ -*-
/*!
 * @file StringUtil.h
 * @brief String operation utility
 * @date $Date: 2007-12-31 03:08:07 $
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2003-2008
 *     Noriaki Ando
 *     Task-intelligence Research Group,
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id: StringUtil.h 826 2008-08-26 08:13:39Z n-ando $
 *
 */

#ifndef COIL_STRINGUTIL_H
#define COIL_STRINGUTIL_H

#include <string>
#include <vector>
#include <sstream>

// Cygwin's gcc does not provide wstring type
#if defined(Cygwin) && ( __GNUC__ < 4 )
namespace std
{
  typedef basic_string<wchar_t> wstring;
}
#endif

namespace coil
{
  typedef std::vector<std::string> vstring;

  /*!
   * @if jp
   * @brief string ���� wstring �ւ̕ϊ�
   *
   * �^����ꂽ string ������� wstring ������ɕϊ�
   *
   * @param str std::string �^�̓��͕�����
   * @return std::wstring �^�̏o�͕�����
   *
   * @else
   * @brief string to wstring conversion
   *
   * This function convert from a string to a wstring.
   * 
   * @param str The input std::string type string
   * @return Converted std::wstring type string
   *
   * @endif
   */
  std::wstring string2wstring(std::string str);

  /*!
   * @if jp
   * @brief wstring ���� string �ւ̕ϊ�
   *
   * �^����ꂽ wstring ������� string ������ɕϊ�
   *
   * @param str std::wstring �^�̓��͕�����
   * @return std::string �^�̏o�͕�����
   *
   * @else
   * @brief wstring to string conversion
   *
   * This function convert from a wstring to a string.
   * 
   * @param str The input std::wstring type string
   * @return Converted std::string type string
   *
   * @endif
   */
  std::string wstring2string(std::wstring wstr);

  /*!
   * @if jp
   * @brief �啶���ւ̕ϊ�
   *
   * �^����ꂽ�������啶���ɕϊ�
   *
   * @param str ���͕�����
   *
   * @else
   * @brief Uppercase String Transformation
   *
   * This function transforms a given string to uppercase letters
   * 
   * @param str The input string
   *
   * @endif
   */
  void toUpper(std::string& str);

  /*!
   * @if jp
   * @brief �������ւ̕ϊ�
   *
   * �^����ꂽ��������������ɕϊ�
   *
   * @param str ���͕�����
   *
   * @else
   * @brief Lowercase String Transformation
   *
   * This function transforms a given string to lowercase letters
   * 
   * @param str The input string
   *
   * @endif
   */
  void toLower(std::string& str);

  /*!
   * @if jp
   * @brief ���̓X�g���[������1�s�ǂݍ���
   *
   * ���̓X�g���[������1�s�ǂݍ��ށB
   * ���̓X�g���[���͂̉��s�R�[�h��UNIX, Windows�̉��s�R�[�h�̂����ꂩ�A
   * �������͍��݂��Ă��Ă��悢�B
   *
   * @param istr ���̓X�g���[��
   * @param line �ǂݍ��񂾕�������i�[����ϐ�
   *
   * @return ���s�����������ǂݍ��񂾕�����̒���
   *
   * @else
   * @brief Read a line from input stream
   *
   * This function reads a line from input stream.
   * UNIX, Windows or mixed line feed code is acceptable.
   *
   * @param istr The input stream.
   * @param line The output variable to store string to be read.
   *
   * @return The length of read string except line feed character.
   *
   * @endif
   */
  int getlinePortable(std::istream& istr, std::string& line);
  
  /*!
   * @if jp
   * @brief �����񂪃G�X�P�[�v����Ă��邩���f����
   *
   * �w�肳�ꂽ�������G�X�P�[�v����Ă��邩�ǂ����𔻒f����B
   *
   * @param str �G�X�P�[�v����Ă��邩�ǂ������f���镶�����܂ޕ�����
   * @param pos �G�X�P�[�v����Ă��邩�ǂ������f���镶���̈ʒu
   *
   * @return �w�肵���������G�X�P�[�v����Ă���� true, ����ȊO�� false
   *
   * @else
   * @brief Check whether the character is escaped or not
   *
   * Check whether the specified character is escaped or not
   *
   * @param str The string that includes the character to be investigated.
   * @param pos The position of the character to be investigated.
   *
   * @return True if the specified character is escaped, else False.
   *
   * @endif
   */
  bool isEscaped(const std::string& str, std::string::size_type pos);
  
  /*!
   * @if jp
   * @brief ��������G�X�P�[�v����
   *
   * ���̕������G�X�P�[�v�V�[�P���X�ɕϊ�����B<br>
   * HT -> "\t" <br>
   * LF -> "\n" <br>
   * CR -> "\r" <br>
   * FF -> "\f" <br>
   * �V���O���N�I�[�g�A�_�u���N�I�[�g�ɂ��Ă͂Ƃ��ɏ����͂��Ȃ��B
   *
   * @param str �G�X�P�[�v�����Ώە�����
   *
   * @return �G�X�P�[�v�������ʕ�����
   *
   * @else
   *
   * @brief Escape string
   *
   * The following characters are converted. <br>
   * HT -> "\t" <br>
   * LF -> "\n" <br>
   * CR -> "\r" <br>
   * FF -> "\f" <br>
   * Single quote and double quote are not processed.
   *
   * @param str The target string for the escape
   *
   * @return Result string of the escape
   *
   * @endif
   */
  std::string escape(const std::string str);
  
  /*!
   * @if jp
   * @brief ������̃G�X�P�[�v��߂�
   *
   * ���̃G�X�P�[�v�V�[�P���X�𕶎��ɕϊ�����B<br>
   * "\t" -> HT <br>
   * "\n" -> LF <br>
   * "\r" -> CR <br>
   * "\f" -> FF <br>
   * "\"" -> "  <br>
   * "\'" -> '  <br>
   * ���G�X�P�[�v�����̊��S�ȋt�ϊ��ɂ͂Ȃ��Ă��Ȃ����߁A���ӂ��K�v�B
   *
   * @param str �A���G�X�P�[�v�����Ώە�����
   *
   * @return �A���G�X�P�[�v�������ʕ�����
   *
   * @else
   *
   * @brief Unescape string
   *
   * The following characters are converted. <br>
   * "\t" -> HT <br>
   * "\n" -> LF <br>
   * "\r" -> CR <br>
   * "\f" -> FF <br>
   * "\"" -> "  <br>
   * "\'" -> '  <br>
   * Note: This is not complete inversion of the escape processing.
   *
   * @param str The target string for the unescape
   *
   * @return Result string of the unescape
   *
   * @endif
   */
  std::string unescape(const std::string str);

  /*!
   * @if jp
   * @brief ������̋󔒕������폜����
   *
   * �^����ꂽ������̋󔒕������폜����B
   * �󔒕����Ƃ��Ĉ����̂�' '(�X�y�[�X)��'\\t'(�^�u)�B
   *
   * @param str �󔒕����폜����������
   *
   * @else
   * @brief Erase blank characters of string
   *
   * Erase blank characters that exist at the head of the given string.
   * Space ' 'and tab '\\t' are supported as the blank character.
   *
   * @param str The target blank characters of string for the erase
   *
   * @endif
   */
  void eraseBlank(std::string& str);

  /*!
   * @if jp
   * @brief ������̐擪�̋󔒕������폜����
   *
   * �^����ꂽ������̐擪�ɑ��݂���󔒕������폜����B
   * �󔒕����Ƃ��Ĉ����̂�' '(�X�y�[�X)��'\\t'(�^�u)�B
   *
   * @param str �擪�󔒕����폜����������
   *
   * @else
   * @brief Erase the head blank characters of string
   *
   * Erase the blank characters that exist at the head of the given string.
   * Space ' 'and tab '\\t' are supported as the blank character.
   *
   * @param str The target head blank characters of string for the erase
   *
   * @endif
   */
  void eraseHeadBlank(std::string& str);
  
  /*!
   * @if jp
   * @brief ������̖����̋󔒕������폜����
   *
   * �^����ꂽ������̖����ɑ��݂���󔒕������폜����B
   * �󔒕����Ƃ��Ĉ����̂�' '(�X�y�[�X)��'\\t'(�^�u)�B
   *
   * @param str �����󔒕����폜����������
   *
   * @else
   * @brief Erase the tail blank characters of string
   *
   * Erase the blank characters that exist at the tail of the given
   * string.  Space ' 'and tab '\\t' are supported as the blank
   * character.
   *
   * @param str The target tail blank characters of string for the erase
   *
   * @endif
   */
  void eraseTailBlank(std::string& str);

  /*!
   * @if jp
   * @brief ������̐擪�E�����̋󔒕������폜����
   *
   * �^����ꂽ������̐擪����і����ɑ��݂���󔒕������폜����B
   * �󔒕����Ƃ��Ĉ����̂�' '(�X�y�[�X)��'\\t'(�^�u)�B
   *
   * @param str �擪�����󔒕����폜����������
   *
   * @else
   * @brief Erase the head blank and the tail blank characters of string
   *
   * Erase the head blank characters and the blank characters that
   * exist at the tail of the given string.  Space ' 'and tab '\\t'
   * are supported as the blank character.
   *
   * @param str The target tail blank characters of string for the erase
   *
   * @endif
   */
  void eraseBothEndsBlank(std::string& str);

  /*!
   * @if jp
   * @brief ������𐳋K������
   *
   * �^����ꂽ������̐擪����і����ɑ��݂���󔒕������폜���A
   * �p�������ׂď������ɕϊ�����B
   *
   * @param str �����Ώە�����
   *
   * @else
   * @brief Erase the head/tail blank and replace upper case to lower case
   *
   * Erase the head blank characters and the blank characters that
   * exist at the tail of the given string.  Space ' 'and tab '\\t'
   * are supported as the blank character.
   * And all upper case cahracters are converted into lower case.
   *
   * @param str The target string for the erase
   *
   * @endif
   */
  std::string normalize(std::string& str);
  
  /*!
   * @if jp
   * @brief �������u��������
   *
   * �^����ꂽ������ɑ΂��āA�w�肵�������̒u���������s���B
   *
   * @param str �u�����������Ώە�����
   * @param from �u��������
   * @param to �u���敶��
   *
   * @else
   * @brief Replace string
   *
   * Replace the given string with the specified characters.
   *
   * @param str The target characters of string for replacement processing
   * @param from Characters of replacement source
   * @param to Characters of replacement destination
   *
   * @endif
   */
  unsigned int replaceString(std::string& str, const std::string from,
                             const std::string to);
  
  /*!
   * @if jp
   * @brief ������𕪊������ŕ�������
   * 
   * �ݒ肳�ꂽ�������^����ꂽ�f���~�^�ŕ�������B
   *
   * @param input �����Ώە�����
   * @param delimiter ����������(�f���~�^)
   *
   * @return �����񕪊����ʃ��X�g
   *
   * @else
   * @brief Split string by delimiter
   * 
   * Split the set string by the given delimiter
   *
   * @param input The target characters of string for split
   * @param delimiter Split string (delimiter)
   *
   * @return Split string result list
   *
   * @endif
   */
  vstring split(const std::string& input,
                const std::string& delimiter,
                bool ignore_empty = false);
  
  /*!
   * @if jp
   * @brief �^����ꂽ�������bool�l�ɕϊ�����
   * 
   * �w�肳�ꂽ��������Atrue�\��������Afalse�\��������Ɣ�r���A���̌��ʂ�
   * bool�l�Ƃ��ĕԂ��B
   * ��r�̌��ʁAtrue�\��������Afalse�\��������̂ǂ���Ƃ���v���Ȃ��ꍇ�́A
   * �^����ꂽ�f�t�H���g�l��Ԃ��B
   *
   * @param str ���f�Ώە�����
   * @param yes true�\��������
   * @param no false�\��������
   * @param default_value �f�t�H���g�l(�f�t�H���g�l:true)
   * @else
   * @brief Convert given string into bool value
   * 
   * Compare the specified string with the true representation string and
   * the false representation string, and return the result as bool value.
   * If it matches neither the true representation string nor the false
   * representation string as a result of the comparison, the given default
   * value will be return.
   *
   * @param str The target string for investigation
   * @param yes The true representation string
   * @param no The false representation string
   * @param default_value The default value (The default value:true)
   * @endif
   */
  bool toBool(std::string str, std::string yes, std::string no, 
              bool default_value = true);
  /*!
   * @if jp
   * @brief �����񃊃X�g���ɂ��镶���񂪊܂܂�邩�ǂ����𔻒f����
   * 
   * ��1�����ɃJ���}��؂�̃��X�g���A��2�����ɒT���Ώە�������w�肵�A
   * ���̕����񂪑�1�����̒��Ɋ܂܂�邩�𔻒f����B
   *
   * @param list �Ώۃ��X�g
   * @param value �T��������
   * @return true: �܂܂��Afalse: �܂܂�Ȃ�
   *
   * @else
   * @brief Include if a string is included in string list
   * 
   * if the second argument is included in the comma separated string
   * list of the first argument, This operation returns "true value".
   *
   * @param list The target comma separated string
   * @param value The searched string
   * @return true: included, false: not included
   *
   * @endif
   */
  bool includes(const vstring& list, std::string value,
                bool ignore_case = true);

  /*!
   * @if jp
   * @brief �����񃊃X�g���ɂ��镶���񂪊܂܂�邩�ǂ����𔻒f����
   * 
   * ��1�����ɃJ���}��؂�̃��X�g���A��2�����ɒT���Ώە�������w�肵�A
   * ���̕����񂪑�1�����̒��Ɋ܂܂�邩�𔻒f����B
   *
   * @param list �Ώە�����
   * @param value �T��������
   * @return true: �܂܂��Afalse: �܂܂�Ȃ�
   *
   * @else
   * @brief Include if a string is included in string list
   * 
   * if the second argument is included in the comma separated string
   * list of the first argument, This operation returns "true value".
   *
   * @param list The target comma separated string
   * @param value The searched string
   * @return true: included, false: not included
   *
   * @endif
   */
  bool includes(const std::string& list, std::string value,
                bool ignore_case = true);
  
  /*!
   * @if jp
   * @brief �^����ꂽ�����񂪐�΃p�X���ǂ����𔻒f����
   *
   * �^����ꂽ�����񂪐�΃p�X�\���ł��邩�ǂ����𔻒f����B
   * �����񂪈ȉ��̏ꍇ�ɂ͐�΃p�X�Ƃ��Ĕ��f����B
   *  - �擪������'/' (UNIX�̏ꍇ)
   *  - �擪�R�������A���t�@�x�b�g�{'/'�{'\\' (Windows�̏ꍇ)
   *  - �擪�Q������'\\\\' (Windows�l�b�g���[�N�p�X�̏ꍇ)
   *
   * @param str ����Ώە�����
   *
   * @return ��΃p�X���茋��
   *
   * @else
   * @brief Investigate whether the given string is absolute path or not
   *
   * Investigate whether the given string is absolute path or not.
   * Investigate it as an absolute path, if the string is as follows:
   *  - The first character '/' (UNIX)
   *  - The first 3 characters are alphabet �{'/'�{'\\' (Windows)
   *  - The first 2 characters are '\\\\' (Windows network path)
   *
   * @param str The target string for the investigation
   *
   * @return Investigation result of absolute path
   *
   * @endif
   */
  bool isAbsolutePath(const std::string& str);
  
  /*!
   * @if jp
   * @brief �^����ꂽ������URL���ǂ����𔻒f����
   *
   * �^����ꂽ������URL�\�����ǂ����𔻒f����B
   * �^����ꂽ�����񒆂ɁA'://'�Ƃ��������񂪊܂܂�Ă���ꍇ�ɂ�
   * URL�\���Ƃ��Ĕ��f����B
   *
   * @param str ����Ώە�����
   *
   * @return URL���茋��
   *
   * @else
   * @brief Investigate whether the given string is URL or not
   *
   * Investigate whether the given string is URL or not.
   * When the string '://' is included in the given character string,
   * make it of URL representation.
   *
   * @param str The target string for investigation
   *
   * @return URL investigation result
   *
   * @endif
   */
  bool isURL(const std::string& str);
  
  /*!
   * @if jp
   * @brief �^����ꂽ�I�u�W�F�N�g��std::string�ɕϊ�
   *
   * �����Ŏw�肳�ꂽ�I�u�W�F�N�g�𕶎���ɕϊ�����B
   *
   * @param n �ϊ��ΏۃI�u�W�F�N�g
   *
   * @return ������ϊ�����
   *
   * @else
   * @brief Convert the given object to std::string
   *
   * Convert the object specified by the argument to string.
   *
   * @param n The target object for conversion
   *
   * @return String conversion result
   *
   * @endif
   */
  template <class Printable>
  std::string otos(Printable n)
  {
    std::stringstream str_stream;
    str_stream << n;
    return str_stream.str();
  };
  
  /*!
   * @if jp
   * @brief �^����ꂽstd::string���I�u�W�F�N�g�ɕϊ�
   *
   * �����ŗ^����ꂽ��������w�肳�ꂽ�I�u�W�F�N�g�ɕϊ�����B
   *
   * @param val �ϊ���I�u�W�F�N�g
   * @param str �ϊ���������
   *
   * @return true: ����, false: ���s
   *
   * @else
   * @brief Convert the given std::string to object.
   *
   * Convert string given by the argument to specified object.
   *
   * @param val The object of conversion destination
   * @param str String of conversion source
   *
   * @return true: successful, false: failed
   *
   * @endif
   */
  template <typename To>
  bool stringTo(To& val, const char* str)
  {
    if (str == 0) { return false; }

    std::stringstream s;
    if ((s << str).fail()) { return false; }
    if ((s >> val).fail()) { return false; }
    return true;
  }
  
  /*!
   * @if jp
   * @brief �^����ꂽ�������std::string�ɕϊ�
   *
   * �����ŗ^����ꂽ�������std::string�ɕϊ�����B
   *
   * @param val �ϊ��敶����
   * @param str �ϊ���������
   *
   * @return true: ����, false: ���s
   *
   * @else
   * @brief Convert the given string to std::string.
   *
   * Convert string given by the argument to std::string.
   *
   * @param val String of conversion destination
   * @param str String of conversion source
   *
   * @return true: successful, false: failed
   *
   * @endif
   */
  template<>
  bool stringTo<std::string>(std::string& val, const char* str);

  /*!
   * @if jp
   * @brief �^����ꂽ�����񃊃X�g����d�����폜
   *
   * �����ŗ^����ꂽ�����񃊃X�g����d�����폜�������X�g���쐬����B
   *
   * @param sv �m�F�������񃊃X�g
   *
   * @return �d���폜�������ʃ��X�g
   *
   * @else
   * @brief Eliminate duplication from the given string list
   *
   * Create a list of eliminating duplication from the string list
   * given by the argument.
   *
   * @param sv The string list for confirmation source
   *
   * @return Eliminating duplication result list
   *
   * @endif
   */
  vstring unique_sv(vstring sv);
  
  /*!
   * @if jp
   * @brief �^����ꂽ�����񃊃X�g����CSV�𐶐�
   *
   * �����ŗ^����ꂽ�����񃊃X�g�̊e�v�f����ׂ�CSV�𐶐�����B
   * �����񃊃X�g����̏ꍇ�ɂ͋󔒕�����Ԃ��B
   *
   * @param sv CSV�ϊ��Ώە����񃊃X�g
   *
   * @return CSV�ϊ����ʕ�����
   *
   * @else
   * @brief Create CSV file from the given string list
   *
   * Create CSV that arranged each element of the character string
   * list given by the argument.
   * If the string list is empty, the null will be returned.
   *
   * @param sv The target string list for creating CSV
   *
   * @return String of CSV creating result
   *
   * @endif
   */
  std::string flatten(vstring sv);
  
  /*!
   * @if jp
   * @brief �^����ꂽ�����񃊃X�g���������X�g�ɕϊ�
   *
   * �����ŗ^����ꂽ�����񃊃X�g�̊e�v�f������'\\0'�������A�������X�g
   * �ɕϊ�����B
   *
   * @param args �ϊ��Ώە����񃊃X�g
   *
   * @return �����ϊ����ʕ�����
   *
   * @else
   * @brief Convert the given string list into the argument list
   *
   * Convert the string list into the argument list by adding '\\0' to
   * each element at the end of the string list given by the argument
   *
   * @param args The target string list for conversion
   *
   * @return String of argument conversion result
   *
   * @endif
   */
  char** toArgv(const vstring& args); 


  /*!
   * @if jp
   * @brief �w�肳�ꂽ�����ɕϊ�
   *
   * �����ŗ^����ꂽ�����ɕϊ����ĕԂ��B
   *
   * @param fmt ����
   *
   * @return �ϊ����ʕ�����
   *
   * @else
   * @brief Convert it into a format given with an argumen
   *
   * Convert it into a format given with an argument and return it.
   *
   * @param fmt Format
   *
   * @return String of conversion result
   *
   * @endif
   */
  std::string sprintf(char const * __restrict fmt, ...);
  
}; // namepsace coil
#endif // COIL_STRINGUTIL_H
