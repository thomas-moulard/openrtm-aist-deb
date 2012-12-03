// -*- C++ -*-
/*!
 * @file Properties.h
 * @brief Property list class (derived from Java Properties)
 * @date $Date: 2007-12-31 03:08:06 $
 * @author Noriaki Ando <n-ando@aist.go.jp>
 *
 * Copyright (C) 2006-2008
 *     Noriaki Ando
 *     Task-intelligence Research Group,
 *     Intelligent Systems Research Institute,
 *     National Institute of
 *         Advanced Industrial Science and Technology (AIST), Japan
 *     All rights reserved.
 *
 * $Id: Properties.h 1971 2010-06-03 08:46:40Z n-ando $
 *
 */

#ifndef COIL_PROPERTIES_H
#define COIL_PROPERTIES_H


#include <string>
#include <vector>
#include <map>
#include <climits>


/*!
 * @if jp
 * @namespace coil 
 *
 * @brief Common Object Interface Layer
 *
 *
 * @else
 * @namespace coil
 *
 * @brief Common Object Interface Layer
 *
 *
 * @endif
 */
namespace coil
{
  /*!
   * @if jp
   *
   * @class Properties
   * @brief �v���p�e�B�Z�b�g��\������N���X
   *
   * Properties �N���X�́A�s�ς̃v���p�e�B�Z�b�g��\���B Properties ���X�g���[��
   * �ɕۊǂ�����A�X�g���[�����烍�[�h�����肷�邱�Ƃ��ł���B
   * �v���p�e�B���X�g�̊e�L�[�A����т���ɑΉ�����l�͕�����ƂȂ��Ă���B
   *
   * �v���p�e�B���X�g�ɂ́A���́u�f�t�H���g�l�v�Ƃ��ĕʂ̃v���p�e�B���X�g������
   * ���Ƃ��ł���B���̃v���p�e�B���X�g�Ńv���p�e�B�L�[��������Ȃ��ƁA����
   * 2�Ԗڂ̃v���p�e�B���X�g�����������B 
   *
   * �v���p�e�B�̎擾�ɂ� getProperty() �A�v���p�e�B�̃Z�b�g�ɂ� setProperty() ��
   * ���������\�b�h���g�p���邱�Ƃ����������B
   *
   * �v���p�e�B���X�g���[���ɕۑ�����Ƃ��A�܂��̓X�g���[�����烍�[�h����Ƃ�
   * �ɁAISO 8859-1 �����G���R�[�f�B���O���g�p�����B���̃G���R�[�f�B���O��
   * ���ڕ\���ł��Ȃ������́A�������Ƃ��ł��Ȃ��B
   *
   * ���̃N���X�́AJava �� Properties �N���X (java.util.Properties) �Ƃقړ��l��
   * ���\�b�h�����B�܂��A���o�͂����t�@�C���� Java �� Properties �N���X��
   * �o�͂�����̂ƌ݊��������邪�AUnicode ���܂ނ��͈̂������Ƃ��ł��Ȃ��B
   *
   * @since 0.4.0
   *
   * @else
   *
   * @class Properties
   * @brief Class represents a set of properties
   *
   * The Properties class represents a persistent set of properties. The
   * Properties can be saved to a stream or loaded from a stream. Each key and
   * its corresponding value in the property list is a string. 
   *
   * A property list can contain another property list as its "defaults". This
   * second property list is searched if the property key is not found in the
   * original property list. 
   *
   * It is recommended to use these method; setProperty() to get properties,
   * setProperty() to set properties. 
   *
   * When propertis are stored in a stream or when they are loaded from
   * the stream, the ISO 8859-1 character encoding is used.
   * Characters that cannot be directly represented in this encoding can be used.
   *
   * This class has almost same methods of Java's Properties class
   * (java.util.Properties). Also, input and output files are compatible with 
   * outputs of Java's Properties class, but Unicode encoded property file
   * is not be supported.
   *
   * @endif
   */
  class Properties
  {
  public:
    /*!
     * @if jp
     *
     * @brief �R���X�g���N�^(root�m�[�h�̂ݍ쐬)
     *
     * key �� value �݂̂�^���� Property �̃��[�g�m�[�h���쐬����B
     * �l�͑S�ăf�t�H���g�l�Ƃ��Đݒ肳���B
     *
     * @param key �v���p�e�B�̃L�[(�f�t�H���g�l:"")
     * @param value �v���p�e�B�̒l(�f�t�H���g�l:"")
     * 
     * @else
     *
     * @brief Constructor(Create only root node)
     *
     * Create a root node of Property with root's key and value.
     * All values are set as default value.
     *
     * @param key Properties's keys(The default values:"")
     * @param value Properties's values(The default values:"")
     * 
     * @endif
     */
    Properties(const char* key = "", const char* value = "");
    
    /*!
     * @if jp
     *
     * @brief �R���X�g���N�^(map�Ńf�t�H���g�l��^����)
     *
     * std::string �� std::map ���f�t�H���g�l�ɂ��� Properties ���쐬����B
     * �l�͑S�ăf�t�H���g�l�Ƃ��Đݒ肳���B
     * 
     * @param defaults �f�t�H���g�l�Ƃ��Ďw�肳���map
     * 
     * @else
     *
     * @brief Constructor(Give the default value with map)
     *
     * Create Properties with default value of std::string map.
     * All values are set as default value.
     * 
     * @param defaults map that is spcified as the default value
     * 
     * @endif
     */
    Properties(std::map<std::string, std::string>& defaults);
    
    /*!
     * @if jp
     *
     * @brief �R���X�g���N�^(char*[] �Ńf�t�H���g�l��^����)
     *
     * �w�肳�ꂽ�f�t�H���g�l������̃v���p�e�B���X�g���쐬����B
     * �l�͑S�ăf�t�H���g�l�Ƃ��Đݒ肳���B
     * �f�t�H���g�l�� char* �̔z��ɂ��^�����Akey �� value �̑΂ɂȂ���
     * ����A���X�g�̏I�[�͔z��̐���\������ num ���A�󕶎��� key �ŗ^������
     * �Ȃ���΂Ȃ�Ȃ��B
     * �ȉ��ɗ�������B
     *
     * <pre>
     * const char* defaults = {
     *     "key1", "value1",
     *     "key2", "value2",
     *     "key3", "value3",
     *     "key4", "value4",
     *     "key5", "value5",
     *     "" };
     * Properties p(defaults);
     * // ��������
     * Properties p(defaults, 10);
     * </pre>
     * 
     * @param defaults �f�t�H���g�l���w�肷��z��
     * @param num �f�t�H���g�l��ݒ肷��v�f��(�f�t�H���g�l:LONG_MAX)
     * 
     * @else
     *
     * @brief Constructor(Give the default value with char*[])
     *
     * Creates an empty property list with the specified defaults.
     * All values are set as the default values.
     * The default values are given by array of char*, which should be pairs
     * of "key" and "value". The end of list is specified by argument "num"
     * which specifies number of array, or null character of key.
     * The following is an example.
     *
     * <pre>
     * const char* defaults = {
     *     "key1", "value1",
     *     "key2", "value2",
     *     "key3", "value3",
     *     "key4", "value4",
     *     "key5", "value5",
     *     "" };
     * Properties p(defaults);
     * // or
     * Properties p(defaults, 10);
     * </pre>
     * 
     * @param defaults Array that specifies the default values
     * @param num Number of elements that specifies the default value
     *            (The default value:LONG_MAX)
     * 
     * @endif
     */
    Properties(const char* defaults[], long num = LONG_MAX);
    
    /*!
     * @if jp
     * @brief �R�s�[�R���X�g���N�^
     *
     * �����ɗ^����ꂽ Properties �̃L�[�A�l����уf�t�H���g�l��
     * �S�Ă��̂܂܃R�s�[�����B
     *
     * @else
     *
     * @brief Copy Constructor
     *
     * All of given Properties's keys, values and default values 
     * are copied to new Properties.
     * 
     * @endif
     */
    Properties(const Properties& prop);
    
    /*!
     * @if jp
     * @brief ������Z�q
     *
     * ���Ӓl�� Properties �̃L�[�A�l����уf�t�H���g�l�͑S�č폜����A
     * �E�Ӓl�� Properties �̃L�[�A�l����уf�t�H���g�l���S�Ă��̂܂�
     * �R�s�[�����B
     *
     * @else
     * @brief Assignment operator
     *
     * All Properties's keys, values and default values of left side
     * are deleted, all Properties's keys, values and default values of
     * right side are copied to new Properties.
     *
     * @endif
     */
    Properties& operator=(const Properties& prop);
    
    /*!
     * @if jp
     *
     * @brief �f�X�g���N�^
     *
     * @else
     *
     * @brief Destructor
     *
     * @endif
     */
    virtual ~Properties(void);
    
    //============================================================
    // public functions
    //============================================================
    
    /*!
     * @if jp
     * @brief Name �̎擾
     *
     * �v���p�e�B�̖��̂��擾����B
     *
     * @return �v���p�e�B��
     *
     * @else
     * @brief Get Names
     *
     * Get Properties's names.
     *
     * @return Properties's names
     *
     * @endif
     */
    inline const char* getName(void) const          {return name.c_str();}
    
    /*!
     * @if jp
     * @brief �l�̎擾
     *
     * �v���p�e�B�̒l���擾����B
     *
     * @return �v���p�e�B�l
     *
     * @else
     * @brief Get values
     *
     * Get Properties's values.
     *
     * @return Properties's values
     *
     * @endif
     */
    inline const char* getValue(void) const         {return value.c_str();}
    
    /*!
     * @if jp
     * @brief �f�t�H���g�l�̎擾
     *
     * �v���p�e�B�̃f�t�H���g�l���擾����B
     *
     * @return �v���p�e�B�f�t�H���g�l
     *
     * @else
     * @brief Get default values
     *
     * Get Properties's default values.
     *
     * @return Properties's default values
     *
     * @endif
     */
    inline const char* getDefaultValue(void) const {return default_value.c_str();}
    
    /*!
     * @if jp
     * @brief �q�v�f�̎擾
     *
     * �v���p�e�B�̎q�v�f���擾����B
     *
     * @return �q�v�f
     *
     * @else
     * @brief Get elements of leaf
     *
     * Get Properties's elements of leaf.
     *
     * @return Elements of leaf
     *
     * @endif
     */
    inline const std::vector<Properties*>& getLeaf(void) const {return leaf;}
    
    /*!
     * @if jp
     * @brief ���[�g�v�f�̎擾
     *
     * �v���p�e�B�̃��[�g�v�f���擾����B
     *
     * @return ���[�g�v�f
     *
     * @else
     * @brief Get root element
     *
     * Get Properties's root element.
     *
     * @return Root element
     *
     * @endif
     */
    inline const Properties* getRoot(void) const    {return root;}
    
    /*!
     * @if jp
     *
     * @brief �w�肳�ꂽ�L�[�����v���p�e�B���A�v���p�e�B���X�g����T��
     *
     * �w�肳�ꂽ�L�[�����v���p�e�B���A�v���p�e�B���X�g����T���B
     * ���̃L�[���v���p�e�B���X�g�ɂȂ��ƁA�f�t�H���g�̃v���p�e�B���X�g�A
     * ����ɂ��̃f�t�H���g�l���J��Ԃ����ׂ���B
     * ���̃v���p�e�B��������Ȃ��ꍇ�́Anull ���Ԃ����B 
     *
     * @param key �v���p�e�B�L�[
     *
     * @return �w�肳�ꂽ�L�[�l�������̃v���p�e�B���X�g�̒l
     *
     * @else
     *
     * @brief Search for the property with the specified key in this property
     *
     * Search for the property with the specified key in this property list.
     * If the key is not found in this property list, the default property list,
     * and its defaults, recursively, are then checked. The method returns null
     * if the property is not found. 
     *
     * @param key The property key.
     *
     * @return The value in this property list with the specified key value.
     *
     * @endif
     */
    const std::string& getProperty(const std::string& key) const;
    
    /*!
     * @if jp
     *
     * @brief �w�肳�ꂽ�L�[�����v���p�e�B���A�v���p�e�B���X�g����T��
     *
     * �w�肳�ꂽ�L�[�����v���p�e�B���A�v���p�e�B���X�g����T���B
     * ���̃L�[���v���p�e�B���X�g�ɂȂ��ꍇ�́A�f�t�H���g�l�̈������Ԃ����B 
     *
     * @param key �v���p�e�B�L�[
     * @param def �f�t�H���g�l
     *
     * @return �w�肳�ꂽ�L�[�l�������̃v���p�e�B���X�g�̒l
     *
     * @else
     *
     * @brief Search for the property with the specified key in property list
     *
     * Search for the property with the specified key in this property list.
     * The method returns the default value argument if the property is not 
     * found.
     *
     * @param key The property key
     * @param def The  default value. 
     *
     * @return The value in this property list with the specified key value.
     *
     * @endif
     */
    const std::string& getProperty(const std::string& key,
				   const std::string& def) const;
    
    /*!
     * @if jp
     *
     * @brief �w�肳�ꂽ�L�[�����v���p�e�B���A�v���p�e�B���X�g����T��
     *
     * �w�肳�ꂽ�L�[�����v���p�e�B��Ԃ��B
     * ���̃L�[���v���p�e�B���X�g�ɂȂ���΃f�t�H���g�l��Ԃ��B
     * ����Ɍ�����Ȃ���΁A�󕶎���Ԃ��B
     *
     * @param key �v���p�e�B�L�[
     *
     * @return �w�肳�ꂽ�L�[�l�������̃v���p�e�B���X�g�̒l
     *
     * @else
     *
     * @brief Search for the property with the specified key in property list
     *
     * Search for the property with the specified key in this property list.
     * If the key is not found in this property list, the default property list,
     * and its defaults, recursively, are then checked. The method returns 
     * empty string if the property is not found. 
     *
     * @param key The property key
     *
     * @return The value in this property list with the specified key value.
     *
     * @endif
     */
    const std::string& operator[](const std::string& key) const;
    
    /*!
     * @if jp
     *
     * @brief �w�肳�ꂽ�L�[�����v���p�e�B���A�v���p�e�B���X�g����T��
     *
     * �w�肳�ꂽ�L�[�����v���p�e�B��Ԃ��B
     * ���̃L�[�̒l���v���p�e�B���X�g�ɂȂ���΃f�t�H���g�l��Ԃ��B
     * ����Ɍ�����Ȃ���΁A�󕶎���Ԃ��B
     * ���Ӓl�ɂȂ�ꍇ�ɁA�����l�����v�f���Ȃ��Ƃ��͗^����ꂽ�L�[
     * �ɑΉ�����v���p�e�B�ɉE�Ӓl��}���B
     *
     * @param key �v���p�e�B�L�[
     *
     * @return �w�肳�ꂽ�L�[�l�������̃v���p�e�B���X�g�̒l
     *
     * @else
     *
     * @brief Search for the property with the specified key in property list
     *
     * Search for the property with the specified key in this property list.
     * If the key is not found in this property list, the default property list,
     * and its defaults, recursively, are then checked. The method returns 
     * empty string if the property is not found.
     * If there is no element with the same value in the left value, insert the
     * right value in corresponding property.
     *
     * @param key The property key
     *
     * @return The value in this property list with the specified key value.
     *
     * @endif
     */
    std::string& operator[](const std::string& key);
    
    /*!
     * @if jp
     * @brief �w�肳�ꂽ�L�[�ɑ΂��ăf�t�H���g�l���擾����
     *
     * �w�肳�ꂽ�L�[�����v���p�e�B�̃f�t�H���g�l��Ԃ��B
     * �w�肳�ꂽ�L�[�����v���p�e�B�����݂��Ȃ��ꍇ�ɂ͋󕶎���Ԃ��B
     *
     * @param key �v���p�e�B�L�[
     *
     * @return �w�肳�ꂽ�L�[�l�����v���p�e�B�̃f�t�H���g�l
     *
     * @else
     * @brief Get the default values with specified key.
     *
     * Return the default values with specified key.
     * If the property with specified key does not exist, the method returns
     * empty string.
     *
     * @param key The property key
     *
     * @return The value in this property list with the specified key value.
     *
     * @endif
     */
    const std::string& getDefault(const std::string& key) const;
    
    /*!
     * @if jp
     *
     * @brief Properties �� value �� key �ɂ��ēo�^����
     *
     * Properties �� value �� key �ɂ��ēo�^����B
     * ���ł� key �ɑ΂���l�������Ă���ꍇ�A�߂�l�ɌÂ��l��Ԃ��B
     *
     * @param key �v���p�e�B���X�g�ɔz�u�����L�[
     * @param value key �ɑΉ�����l 
     *
     * @return �v���p�e�B���X�g�̎w�肳�ꂽ�L�[�̑O�̒l�B���ꂪ�Ȃ��ꍇ�� null
     *
     * @else
     *
     * @brief Set a value associated with key in the property list
     *
     * This method sets the "value" associated with "key" in the property list.
     * If the property list has a value of "key", old value is returned.
     *
     * @param key The key to be placed into this property list.
     * @param value The value corresponding to key. 
     *
     * @return The previous value of the specified key in this property list,
     *         or null if it did not have one.
     *
     *@endif
     */
    std::string setProperty(const std::string& key, const std::string& value);
    
    /*!
     * @if jp
     * @brief �f�t�H���g�l��o�^����
     *
     * key �Ŏw�肳���v�f�Ƀf�t�H���g�l��o�^����B
     *
     * @param key �f�t�H���g�l��o�^����v���p�e�B�̃L�[
     * @param value �o�^�����f�t�H���g�l
     *
     * @return �w�肳�ꂽ�f�t�H���g�l
     *
     * @else
     * @brief Set a default value associated with key in the property list
     *
     * Set the default value to element specified by "key".
     *
     * @param key Property's key to set the default value
     * @param value The default value that is set
     *
     * @return The specified default value
     *
     * @endif
     */
    std::string setDefault(const std::string& key, const std::string& value);
    
    /*!
     * @if jp
     * @brief Properties �Ƀf�t�H���g�l���܂Ƃ߂ēo�^����
     *
     * �z��Ŏw�肳�ꂽ�v�f�Ƀf�t�H���g�l���܂Ƃ߂ēo�^����B
     * �f�t�H���g�l�� char* �̔z��ɂ��^�����Akey �� value �̑΂ɂȂ���
     * ����A���X�g�̏I�[�͔z��̐���\������ num ���A�󕶎��� key �ŗ^������
     * �Ȃ���΂Ȃ�Ȃ��B
     * 
     * @param defaults �f�t�H���g�l���w�肷��z��
     * @param num �f�t�H���g�l��ݒ肷��v�f��(�f�t�H���g�l:LONG_MAX)
     * 
     * @else
     * @brief Set a default value together in the property list
     *
     * Set the default value to the element specified by array together in the
     * property list.
     * The default values are given by array of char*, which should be pairs
     * of "key" and "value". The end of list is specified by argument "num",
     * which specifies number of array or null character of key.
     * 
     * @param defaults Array that specifies the default values
     * @param num Number of elements that specifies the default value
     *            (Default value:LONG_MAX)
     * 
     * @endif
     */
    void setDefaults(const char* defaults[], long num = LONG_MAX);
    
    //============================================================
    // load and save functions
    //============================================================
    /*!
     * @if jp
     *
     * @brief �w�肳�ꂽ�o�̓X�g���[���ɁA�v���p�e�B���X�g���o�͂���
     *
     * �w�肳�ꂽ�o�̓X�g���[���ɁA�v���p�e�B���X�g���o�͂���B
     * ���̃��\�b�h�͎�Ƀf�o�b�O�ɗp������B
     *
     * @param out �o�̓X�g���[��
     *
     * @else
     *
     * @brief Prints this property list out to the specified output stream
     *
     * Prints this property list out to the specified output stream.
     * This method is useful for debugging.
     *
     * @param out Output stream.
     *
     * @endif
     */
    void list(std::ostream& out);
    
    /*!
     * @if jp
     *
     * @brief ���̓X�g���[������L�[�Ɨv�f���΂ɂȂ����v���p�e�B���X�g��ǂݍ���
     *
     * ���̓X�g���[������L�[�Ɨv�f���΂ɂȂ����v���p�e�B���X�g��ǂݍ��ށB
     * �X�g���[���́AISO 8859-1 �����G���R�[�f�B���O���g�p���Ă���Ƃ݂Ȃ����B
     * �e�v���p�e�B�́A���̓X�g���[���ɍs�P�ʂœo�^����Ă�����̂Ƃ݂Ȃ���A
     * �e�s�͍s��؂蕶�� (\\n�A\\r�A�܂��� \\r\\n) �ŏI���B
     * ���̓X�g���[������ǂݍ��񂾍s�́A���̓X�g���[���Ńt�@�C���̏I����
     * �B����܂ŏ��������B
     *
     * �󔒕��������̍s�A�܂��͍ŏ��̔�󔒕����� ASCII ���� # �܂��� ! �ł���
     * �s�͖��������B�܂�A# �܂��� ! �̓R�����g�s�������B
     *
     * �󔒍s�܂��̓R�����g�s�ȊO�̂��ׂĂ̍s�́A�e�[�u���ɒǉ������v���p�e�B
     * ���L�q����B�������A�s�̏I��肪 \ �̏ꍇ�́A���̍s������Όp���s�Ƃ���
     * ������ (���L���Q��)�B �L�[�́A�ŏ��̔�󔒕�������A�ŏ��� ASCII ����
     * =�A:�A�܂��͋󔒕����̒��O�܂ł́A�s���̂��ׂĂ̕�������\�������B
     *
     * �L�[�̏I�������������́A�O�� \ ��t���邱�Ƃɂ��L�[�Ɋ܂߂邱�Ƃ�
     * �ł���B�L�[�̌��̋󔒂͂��ׂăX�L�b�v�����B
     * �L�[�̌��̍ŏ��̔�󔒕����� = �܂��� : �ł���ꍇ�́A�����̃L�[��
     * ��������A���̂��Ƃ̋󔒕��������ׂăX�L�b�v�����B
     * �s���̂���ȊO�̕����͂��ׂāA�֘A�����v�f������̈ꕔ�ƂȂ�B
     * �v�f��������ł́AASCII �G�X�P�[�v�V�[�P���X \\t�A\\n�A\\r�A\\\\�A\\"�A
     * \\'�A\\ (�~�L���ƃX�y�[�X)�A����� \\uxxxx �͔F������A�P�Ƃ̕����ɕϊ�
     * �����B
     * �܂��A�s�̍Ō�̕����� \ �ł���ꍇ�́A���̍s�͌��݂̍s�̌p���Ƃ���
     * ������B���̏ꍇ�A\ �ƍs��؂蕶�����j������A�p���s�̐擪�ɋ󔒂�
     * ����΂�������ׂĔj������A�v�f������̈ꕔ�ɂ͂Ȃ�Ȃ��B 
     *
     * ���Ƃ��΁A���� 3 �s�͂��ꂼ��L�[ Truth �Ɗ֘A�����v�f�l Beauty ��\���B
     * 
     * Truth = Beauty <BR>
     * Truth:Beauty <BR>
     * Truth\\t\\t\\t:Beauty <BR>
     *
     * �܂��A���� 3 �s�� 1 �̃v���p�e�B��\���B 
     *
     * fruits\\t\\t\\t\\tapple, banana, pear, \ <BR>
     *                                  cantaloupe, watermelon, \ <BR>
     *                                  kiwi, mango <BR>
     * �L�[�� fruits �ŁA���̗v�f�Ɋ֘A�t�������B 
     * "apple, banana, pear, cantaloupe, watermelon, kiwi, mango"
     * �ŏI�I�Ȍ��ʂŃR���}�̂��ƂɕK���X�y�[�X���\�������悤�ɁA
     * �e \ �̑O�ɃX�y�[�X������B�s�̏I�������� \ �ƁA�p���s�̐擪�ɂ���
     * �󔒂͔j������A���̕����ɒu������Ȃ��B 
     * �܂��A���� 3 �Ԗڂ̗�ł́A�L�[�� cheeses �ŁA�֘A�����v�f����̕�����
     * �ł��邱�Ƃ�\���B 
     *
     * cheeses <BR>
     * �L�[�́Acheeses �ŁA�֘A�v�f�͋�̕�����ł��邱�Ƃ��w�肵�Ă���B 
     *
     * @param inStream ���̓X�g���[�� 
     *
     * @else
     *
     * @brief Loads property list that consists of key:value from input stream
     *
     * Reads a property list (key and element pairs) from the input stream.
     * The stream is assumed to be using the ISO 8859-1 character encoding.
     * Each property is assumed to be registered in the input stream by each
     * line, and each line terminator is should be a line break characters
     * (\\n or \\r or \\r\\n).
     * Lines are read from the input stream until end of file is reached. 
     *
     * A line that contains only white space characters or a line that its
     * first non-white space character is an ASCII '#' or '!' is ignored.
     * In a word, '#' or '!' represents comment lines.
     *
     * All lines except the blank line or comment line is described the property
     * that added to the table. However, if the line terminator is '\' and the 
     * next line continues, it is treated as a continuation line (See below).
     * The key is composed of all characters.
     * All of these key termination characters in the line starting with the 
     * first non-white space character and up to, but not including, the first
     * unescaped '=', ':', or white space character other than a line 
     * terminator. 
     * 
     * Line terminator characters can be included using \ escape sequences.
     * Any white space after the key is skipped.
     * If the first non-white space character after the key is '=' or ':',
     * then it is ignored and any white space characters after it are also 
     * skipped.
     * All remaining characters on the line become part of the associated element
     * string.
     * In element string, ASCII escape sequence such as \\t and \\n and \\r
     * and \\\\ and \\" and \\' and \\ (backslash character and space) 
     * and \\uxxxx have affect and they will be converted into a single 
     * character.
     * Also, if termination character in the line is \, the next line will be  
     * treated as continuing. In that case, \ and break character will be 
     * destroyed, and also its first space character will be destroyed, 
     * so these characters on the line will not become part of the element 
     * string.
     *
     * As an example, each of the following three lines specifies the key 
     * "Truth" and the associated element value "Beauty": 
     * 
     * Truth = Beauty <BR>
     * Truth:Beauty <BR>
     * Truth\\t\\t\\t:Beauty <BR>
     *
     * As another example, the following three lines specify a single 
     * property: 
     *
     * fruits\\t\\t\\t\\tapple, banana, pear, \ <BR>
     *                                  cantaloupe, watermelon, \ <BR>
     *                                  kiwi, mango <BR>
     * The key is "fruits" and the associated element is: 
     * "apple, banana, pear, cantaloupe, watermelon, kiwi, mango".
     * Note that a space appears before each \ so that a space will
     * each comma in the final result; the \, line terminator, and leading white
     * space on the continuation line are merely discarded and are not replaced
     * by one or more other characters. 
     * As a third example, the line: 
     *
     * cheeses <BR>
     * specifies that the key is "cheeses" and the associated element is the
     * empty string "".
     *
     * @param inStream the input stream.
     *
     * @endif
     */
    void load(std::istream& inStream);
    
    /*!
     * @if jp
     *
     * @brief �v���p�e�B���X�g���w�肳�ꂽ�X�g���[���ɕۑ�����
     *
     * ��������Ă��܂���B�v���p�e�B���X�g�̕ۑ����@�Ƃ��ẮA
     * store(ostream out, string header) ���\�b�h�̎g�p�����������B
     * ���̃��\�b�h�� Java Properties �Ƃ̌݊����̂��߂ɒ�`����Ă���B
     *
     * @param out �o�̓X�g���[��
     * @param header �v���p�e�B���X�g�̋L�q 
     *
     * @else
     *
     * @brief Save the property list to the specified stream
     *
     * It is not recommended. To save the property list,
     * the store(ostream out, string header) method is recommended.
     * This method is defined for compatibility of Java Properties.
     *
     * @param out The output stream
     * @param header A description of the property list
     *
     * @endif
     */
    void save(std::ostream& out, const std::string& header);
    
    /*!
     * @if jp
     *
     * @brief �v���p�e�B���X�g���o�̓X�g���[���֕ۑ�����
     *
     * Properties �e�[�u�����̃v���p�e�B���X�g (�L�[�Ɨv�f�̃y�A) ���Aload
     * ���\�b�h���g���� Properties �e�[�u���Ƀ��[�h����̂ɓK�؂ȃt�H�[�}�b�g��
     * �o�̓X�g���[���ɏ������ށB 
     *
     * Properties �e�[�u�����̃v���p�e�B���X�g (�L�[�Ɨv�f�̃y�A) ���Aload
     * ���\�b�h���g���� Properties �e�[�u���Ƀ��[�h����̂ɓK�؂ȃt�H�[�}�b�g��
     * �o�̓X�g���[���ɏ������ށB�X�g���[���́AISO 8859-1 ����
     * �G���R�[�f�B���O���g�p���ď������܂��B 
     * Properties �e�[�u�� (���݂���ꍇ) �̃f�t�H���g�e�[�u�������
     * �v���p�e�B�́A���̃��\�b�h�ɂ���Ă͏������܂�Ȃ��B 
     *
     * header ������ null �łȂ��ꍇ�́AASCII ������ #�Aheader �̕�����A
     * ����эs��؂蕶�����ŏ��ɏo�̓X�g���[���ɏ������܂�܂��B���̂��߁A
     * header �͎��ʃR�����g�Ƃ��Ďg�����Ƃ��ł���B 
     *
     * ���ɁAASCII ������ #�A���݂̓��� (Date �� toString ���\�b�h�ɂ����
     * ���ݎ��������������̂Ɠ��l)�A����� Writer �ɂ���Đ��������s��؂�
     * ����Ȃ�R�����g�s���������܂��B 
     *
     * �����āA Properties �e�[�u�����̂��ׂẴG���g���� 1 �s�������o�����B
     * �e�G���g���̃L�[������AASCII ������=�A�֘A�����v�f�����񂪏������܂��B
     * �v�f������̊e�����́A�G�X�P�[�v�V�[�P���X�Ƃ��ĕ`�悷��K�v�����邩
     * �ǂ����m�F�����BASCII ������ \�A�^�u�A���s�A����ѕ��A�͂��ꂼ�� \\\\�A
     * \\t�A\\n�A����� \\r �Ƃ��ď������܂��B\\u0020 ��菬�������������
     * \\u007E ���傫�������́A�Ή����� 16 �i�l xxxx ���g���� \\uxxxx �Ƃ���
     * �������܂��B���ߍ��݋󔒕����ł��㏑���󔒕����ł��Ȃ���s�󔒕����́A
     * �O�� \ ��t���ď������܂��B�L�[�ƒl�̕��� #�A!�A=�A����� : �́A
     * �K�����������[�h�����悤�ɁA�O�ɃX���b�V����t���ď������܂��B 
     *
     * �G���g�����������܂ꂽ���ƂŁA�o�̓X�g���[�����t���b�V�������B
     * �o�̓X�g���[���͂��̃��\�b�h���畜�A�������Ƃ��J�����܂܂ƂȂ�B 
     *
     * @param out �o�̓X�g���[��
     * @param header �v���p�e�B���X�g�̋L�q 
     *
     * @else
     *
     * @brief Stores property list to the output stream
     *
     * Write this property list (key and element pairs) in this Properties 
     * table to the output stream in a format suitable for loading into a 
     * Properties table using the load method. The stream is written using the 
     * ISO 8859-1 character encoding. 
     * Properties from the defaults table of this Properties table (if any) are
     * not written out by this method. 
     *
     * If the header argument is not null, then an ASCII # character, the
     * comments string, and a line separator are first written to the output
     * stream. Thus, the header can serve as an identifying comment. 
     *
     * Next, a comment line is always written, consisting of an ASCII #
     * character, the current date and time (as if produced by the toString
     * method of Date for the current time), and a line separator as generated
     * by the Writer. 
     *
     * Then every entry in this Properties table is written out, one per line.
     * For each entry the key string is written, then an ASCII =, then the
     * associated element string. Each character of the key and element strings
     * is examined to see whether it should be rendered as an escape sequence.
     * The ASCII characters \, tab, form feed, newline, and carriage return are
     * written as \\\\, \\t, \\f \\n, and \\r, respectively. Characters less than
     * \\u0020 and characters greater than \\u007E are written as \\uxxxx for the
     * appropriate hexadecimal value xxxx. For the key, all space characters are
     * written with a preceding \ character. For the element, leading space
     * characters, but not embedded or trailing space characters, are written
     * with a preceding \ character. The key and element characters #, !, =, and
     * : are written with a preceding backslash to ensure that they are properly
     * loaded. 
     *
     * After the entries have been written, the output stream is flushed. The
     * output stream remains open after this method returns. 
     *
     * @param out An output stream.
     * @param header The description of the property list.
     *
     * @endif
     */
    void store(std::ostream& out, const std::string& header);
    
    //============================================================
    // other util functions
    //============================================================
    /*!
     * @if jp
     *
     * @brief �v���p�e�B�̃L�[�̃��X�g�� vector �ŕԂ�
     *
     * ���C���v���p�e�B���X�g�ɓ������O�̃L�[��������Ȃ��ꍇ�́A�f�t�H���g��
     * �v���p�e�B���X�g�ɂ���ʂ̃L�[���܂ށA���̃v���p�e�B���X�g�ɂ��邷�ׂ�
     * �̃L�[�̃��X�g��Ԃ��B 
     *
     * @return �v���p�e�B���X�g�ɂ��邷�ׂẴL�[�̃��X�g�B
     *         �f�t�H���g�̃v���p�e�B���X�g�ɂ���L�[���܂�
     *
     * @else
     *
     * @brief Return an vector of all the keys in this property
     *
     * Returns an enumeration of all the keys in this property list, including
     * distinct keys in the default property list if a key of the same name has
     * not already been found from the main properties list.
     *
     * @return A vector of all the keys in this property list, including the
     *         keys in the default property list.
     *
     * @endif
     */
    std::vector<std::string> propertyNames(void) const;
    
    /*!
     * @if jp
     * @brief �v���p�e�B�̐����擾����
     *
     * �ݒ�ς݂̃v���p�e�B�����擾����B
     *
     * @return �v���p�e�B��
     *
     * @else
     * @brief Get the number of Properties
     *
     * Get the number of Properties that has already set.
     *
     * @return Number of Properties
     *
     * @endif
     */
    int size(void) const;
    
    /*!
     * @if jp
     * @brief �m�[�h���擾����
     *
     * �w�肵���L�[�����m�[�h���擾����B
     * ���݂��Ȃ��L�[�A����ы󕶎��̏ꍇ 0 ��Ԃ��B
     *
     * @param key �擾�Ώۃm�[�h�̃L�[
     *
     * @return �Ώۃm�[�h
     *
     * @else
     * @brief Get node of properties
     *
     * Get node with specified key.
     *
     * @param key Target node key for getting
     *
     * @return Target node
     *
     * @endif
     */
    Properties* const findNode(const std::string& key) const;
    /*!
     * @if jp
     * @brief �m�[�h���擾����
     *
     * �w�肵���L�[�����m�[�h���擾����B
     * ���݂��Ȃ��L�[�A����ы󕶎��̏ꍇ 0 ��Ԃ��B
     *
     * @param key �擾�Ώۃm�[�h�̃L�[
     *
     * @return �Ώۃm�[�h
     *
     * @else
     * @brief Get node of properties
     *
     * Get node with specified key.
     *
     * @param key Target node key for getting
     *
     * @return Target node
     *
     * @endif
     */
    Properties& getNode(const std::string& key);
    
    /*!
     * @if jp
     * @brief �V�K�m�[�h�𐶐�����
     *
     * �w�肵���L�[�����V�K�m�[�h�𐶐�����B
     * ���ɓ���L�[�����m�[�h���o�^�ς݂̏ꍇ�ɂ̓G���[��Ԃ��B
     *
     * @param key �V�K�m�[�h�̃L�[
     *
     * @return �V�K�m�[�h��������
     *         �w�肵���L�[�����m�[�h�����ɑ��݂���ꍇ�ɂ�false
     *
     * @else
     * @brief Create newly node of Properties
     *
     * Create nowly node with specified key.
     * If the node with the same key has been registered, error will be returned.
     *
     * @param key Newly node key
     *
     * @return Newly node creation result.
     *         false will be returned if the node with specified key has already
     *         existed.
     *
     * @endif
     */
    bool createNode(const std::string& key);
    
    /*!
     * @if jp
     * @brief �m�[�h���폜����
     *
     * �w�肵�����̂����v���p�e�B���폜����B
     * �폜�����v���p�e�B��Ԃ��B
     *
     * @param leaf_name �폜�Ώۃv���p�e�B����
     *
     * @return �폜�����v���p�e�B
     *
     * @else
     * @brief Remove node of Properties
     *
     * Remove properties with specified name.
     * Properties that were deleted will be returned.
     *
     * @param leaf_name Target property's name for the delete
     *
     * @return Deleted properties
     *
     * @endif
     */
    Properties* removeNode(const char* leaf_name);
    
    /*!
     * @if jp
     * @brief �q�m�[�h��key�����邩�ǂ���
     *
     * �w�肵���L�[�����q�m�[�h�����݂��邩�ǂ����m�F����B
     * ���݂���ꍇ�A�q�m�[�h��Ԃ��B
     *
     * @param key �m�F�Ώۂ̃L�[
     *
     * @return �q�m�[�h
     *
     * @else
     * @brief Check whether key exists in the children
     *
     * Check whether the children with specified key exist.
     * If the children exist, they will be returned.
     *
     * @param key Check key
     *
     * @return Children node
     *
     * @endif
     */
    Properties* hasKey(const char* key) const;
    
    /*!
     * @if jp
     * @brief �q�m�[�h��S�č폜����
     * @else
     * @brief Clear the children
     * @endif
     */
    void clear(void);
    
    /*!
     * @if jp
     * @brief Property���}�[�W����
     *
     * ���݂̃v���p�e�B�ɐݒ肵���v���p�e�B���}�[�W����B
     *
     * @param prop �}�[�W����v���p�e�B
     *
     * @return �v���p�e�B�}�[�W����
     *
     * @else
     * @brief Merge properties
     *
     * Merge properties that have set to the current properties.
     *
     * @param prop Properties for the merge
     *
     * @return Property merge result
     *
     * @endif
     */
    Properties& operator<<(const Properties& prop);
    
  protected:
    /*!
     * @if jp
     * @brief ��������L�[�ƒl�̃y�A�ɕ�������
     *
     * �^����ꂽ��������A�ݒ肳�ꂽ�f���~�^�ŃL�[�ƒl�̃y�A�ɕ�������B
     * �܂��ŏ��ɗ^����ꂽ�������':'��������'='���܂܂�邩���������A
     * �ǂ��炩�̕������܂܂�Ă���ꍇ�ɂ͂�����f���~�^�Ƃ��Ďg�p����B
     * �����Ƃ��܂܂�Ă��Ȃ��ꍇ�ɂ́A' '(�X�y�[�X)��p���ĕ��������݂�B
     * �S�Ẵf���~�^��₪�܂܂�Ă��Ȃ��ꍇ�ɂ́A�^����ꂽ��������L�[�Ƃ���
     * �ݒ肵�A�l�ɋ�̕������ݒ肷��B
     * �ǂ̃f���~�^���ɂ��Ă��G�X�P�[�v����Ă���(���O��'\'���ݒ肳��Ă���)
     * �ꍇ�ɂ́A�f���~�^�Ƃ��Ďg�p���Ȃ��B
     *
     * @param str �����Ώە�����
     * @param key �������ʃL�[
     * @param value �������ʒl
     *
     * @else
     * @brief Split the string into a pair of the key and the value.
     *
     * Split the given string into a pair of the key and the value with
     * the set delimiter.
     * First, search whether the fist given string includes ':' or '=', and 
     * if either character is included, it is used as delimiter.
     * If neither is included, try to divide it with ' '(space).
     * When all delimiter candidates are not included, set the given string
     * as key then set empty string to the its value.
     * If any delimiter candidate is escaped ('\' is set right before it),
     * this method does not use as delimiter.
     *
     * @param str Target string for the division
     * @param key Division result key
     * @param value Division result value
     *
     * @endif
     */
    static void splitKeyValue(const std::string& str, std::string& key,
			      std::string& value);
    
    /*!
     * @if jp
     * @brief ������𕪊�����
     *
     * �^����ꂽ��������A�^����ꂽ�f���~�^�ŕ�������B
     * �^����ꂽ�����񂪋�̏ꍇ�́A�G���[��Ԃ��B
     * �^����ꂽ�f���~�^���G�X�P�[�v����Ă���(���O��'\'���ݒ肳��Ă���)�ꍇ
     * �ɂ́A�f���~�^�Ƃ��Ďg�p���Ȃ��B
     *
     * @param str �����Ώە�����
     * @param delim �f���~�^
     * @param value �������ʒl���X�g
     *
     * @return ������������
     *
     * @else
     * @brief Split the string
     *
     * Divide given string with given delimiter.
     * If the given string is empty, error will be returned.
     * When the given delimiter is escaped ('\' is set right before it)
     * this method does not use as delimiter.
     *
     * @param str Target string for the division
     * @param delim Delimiter
     * @param value Division result list
     *
     * @return Division result
     *
     * @endif
     */
    static bool split(const std::string& str, const char delim,
		      std::vector<std::string>& value);
    
    /*!
     * @if jp
     * @brief �v���p�e�B���擾����
     *
     * �L�[���X�g�Ŏw�肳�ꂽ�v���p�e�B���擾����B
     * �L�[���X�g�ł́A�w�肷��L�[�̃v���p�e�B�ł̊K�w�֌W�����X�g�`���ŕ\��
     * ����B
     * �w�肵���L�[���X�g�ɊY������v���p�e�B�����݂��Ȃ��ꍇ��NULL��Ԃ��B
     *
     * @param keys �擾�Ώۃv���p�e�B�̃L�[�̃��X�g�\��
     * @param index �L�[���X�g�̊K�w��
     * @param curr �����Ώۃv���p�e�B
     *
     * @return �����Ώۃv���p�e�B
     *
     * @else
     * @brief Get properties
     *
     * Get properties specified by key list.
     * In the key list, hierarchical relation in the properties is represented
     * by a list format.
     * If properties corresponding to specified key list do not exist,
     * null will be returned.
     *
     * @param keys Target properties's key list representation for getting
     * @param index Number of hierarchy of key list
     * @param curr Target properties for the search
     *
     * @return Target properties for the search
     *
     * @endif
     */
    static Properties* _getNode(std::vector<std::string>& keys,
				std::vector<Properties*>::size_type index,
				const Properties* curr);
    
    /*!
     * @if jp
     * @brief �v���p�e�B�̖��̃��X�g���擾����
     *
     * �v���p�e�B�̖��̂�'.'��؂�ŕ\���������X�g���擾����B
     *
     * @param names �v���p�e�B�̖��̃��X�g
     * @param curr_name ���݂̃v���p�e�B��
     * @param curr �Ώۃv���p�e�B
     *
     * @else
     * @brief Get property name list
     *
     * Get a list expressed by separating each property name with '.'.
     *
     * @param names Name list of property
     * @param curr_name Current property's name
     * @param curr Target properties
     *
     * @endif
     */
    static void _propertiyNames(std::vector<std::string>& names,
				std::string curr_name,
				const Properties* curr);
    
    /*!
     * @if jp
     * @brief �v���p�e�B�̖��̃��X�g��ۑ�����
     *
     * �v���p�e�B�̖��̂�'.'��؂�ŕ\���������X�g��ۑ�����B
     *
     * @param out �v���p�e�B�̖��̃��X�g�ۑ���̏o�̓X�g���[��
     * @param curr_name ���݂̃v���p�e�B��
     * @param curr �Ώۃv���p�e�B
     *
     * @else
     * @brief Store the property name list
     *
     * Store a list expressed by separating each property name with '.'.
     *
     * @param out Output stream of property's name list of save destination.
     * @param curr_name Current property's name
     * @param curr Target properties
     *
     * @endif
     */
    static void _store(std::ostream& out, std::string curr_name,
		       Properties* curr);
    
    /*!
     * @if jp
     * @brief �v���p�e�B�̓��e��ۑ�����
     *
     * �v���p�e�B�ɐݒ肳�ꂽ���e��ۑ�����B
     * �ۑ����ɂ̓v���p�e�B�K�w�̐[����\���������t�������B
     * �l���ݒ肳��Ă��Ȃ��v���p�e�B�ɂ��ẮA�f�t�H���g�l���o�͂����B
     *
     * @param out �v���p�e�B���e�ۑ���̏o�̓X�g���[��
     * @param curr �Ώۃv���p�e�B
     * @param index ���݂̃v���p�e�B�K�w
     *
     * @else
     * @brief Save property's contents
     *
     * Save the contents that were set to the property.
     * The figure represented the depth of the property hierarchy is
     * added when saving.
     * If property with the value that is not set, the default value will
     * be output.
     *
     * @param out Output stream of property's contents of save destination.
     * @param curr Target property
     * @param index Current property hierarchy
     *
     * @endif
     */
    static std::ostream& _dump(std::ostream& out, const Properties& curr,
			       int index);
    
    /*!
     * @if jp
     * @brief �C���f���g�𐶐�����
     *
     * �w�肳�ꂽ�����ɏ]���Đ��������C���f���g��Ԃ��B
     * �Ԃ����C���f���g�́A�w�萔���~2�̋󔒁B
     *
     * @param index �C���f���g���̎w��
     *
     * @return �������ꂽ�C���f���g
     *
     * @else
     * @brief Create indents
     *
     * Return indents according to specified figure.
     * Returned indents are specified figure x two blanks.
     *
     * @param index The specification of Number of indent
     *
     * @return Created indent
     *
     * @endif
     */
    static std::string indent(int index);
    
  private:
    std::string name;
    std::string value;
    std::string default_value;
    Properties* root;
    std::vector<Properties*> leaf;
    const std::string m_empty;

    /*!
     * @if jp
     * @brief Property���X�g���[���ɏo�͂���
     *
     * Property���X�g���[���ɏo�͂���B
     *
     * @param lhs �o�̓X�g���[��
     * @param rhs �v���p�e�B
     *
     * @return �o�̓X�g���[��
     *
     * @else
     * @brief Output Properties to stream
     *
     * Output Properties to stream.
     *
     * @param lhs Output stream
     * @param rhs Properties
     *
     * @return Output stream
     *
     * @endif
     */
    friend std::ostream& operator<<(std::ostream& lhs, const Properties& rhs);

  };   // class Properties
};     // namespace coil  
#endif // COIL_PROPERTIES_H

