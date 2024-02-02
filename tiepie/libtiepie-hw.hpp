/**
 * \file libtiepie-hw.hpp
 * \brief C++ header with wrapper classes for libtiepie-hw.
 */

#ifndef _LIBTIEPIE_HW_HPP_
#define _LIBTIEPIE_HW_HPP_

#include <vector>
#include <string>
#include <stdexcept>
#include <memory>
#include "libtiepie-hw.h"

namespace TiePie::Hardware {
  using Handle = tiepie_hw_handle;

  class Exception : public std::runtime_error
  {
    protected:
      const tiepie_hw_status m_status;

    public:
      Exception(tiepie_hw_status status, const std::string& what) :
        std::runtime_error(what),
        m_status(status)
      {
      }

      [[nodiscard]] tiepie_hw_status status() const
      {
        return m_status;
      }
  };

  class UnsuccessfulException : public Exception
  {
    public:
      UnsuccessfulException() :
        Exception(TIEPIE_HW_STATUS_UNSUCCESSFUL, "Unsuccessful")
      {
      }
  };

  class NotSupportedException : public Exception
  {
    public:
      NotSupportedException() :
        Exception(TIEPIE_HW_STATUS_NOT_SUPPORTED, "Not supported")
      {
      }
  };

  class InvalidHandleException : public Exception
  {
    public:
      InvalidHandleException() :
        Exception(TIEPIE_HW_STATUS_INVALID_HANDLE, "Invalid handle")
      {
      }
  };

  class InvalidValueException : public Exception
  {
    public:
      InvalidValueException() :
        Exception(TIEPIE_HW_STATUS_INVALID_VALUE, "Invalid value")
      {
      }
  };

  class InvalidChannelException : public Exception
  {
    public:
      InvalidChannelException() :
        Exception(TIEPIE_HW_STATUS_INVALID_CHANNEL, "Invalid channel")
      {
      }
  };

  class InvalidTriggerSourceException : public Exception
  {
    public:
      InvalidTriggerSourceException() :
        Exception(TIEPIE_HW_STATUS_INVALID_TRIGGER_SOURCE, "Invalid trigger source")
      {
      }
  };

  class InvalidDeviceTypeException : public Exception
  {
    public:
      InvalidDeviceTypeException() :
        Exception(TIEPIE_HW_STATUS_INVALID_DEVICE_TYPE, "Invalid device type")
      {
      }
  };

  class InvalidDeviceIndexException : public Exception
  {
    public:
      InvalidDeviceIndexException() :
        Exception(TIEPIE_HW_STATUS_INVALID_DEVICE_INDEX, "Invalid device index")
      {
      }
  };

  class InvalidProductIDException : public Exception
  {
    public:
      InvalidProductIDException() :
        Exception(TIEPIE_HW_STATUS_INVALID_PRODUCT_ID, "Invalid product id")
      {
      }
  };

  class InvalidDeviceSerialNumberException : public Exception
  {
    public:
      InvalidDeviceSerialNumberException() :
        Exception(TIEPIE_HW_STATUS_INVALID_DEVICE_SERIALNUMBER, "Invalid device serialnumber")
      {
      }
  };

  class ObjectGoneException : public Exception
  {
    public:
      ObjectGoneException() :
        Exception(TIEPIE_HW_STATUS_OBJECT_GONE, "Object gone")
      {
      }
  };

  class InternalAddressException : public Exception
  {
    public:
      InternalAddressException() :
        Exception(TIEPIE_HW_STATUS_INTERNAL_ADDRESS, "Internal address")
      {
      }
  };

  class NotControllableException : public Exception
  {
    public:
      NotControllableException() :
        Exception(TIEPIE_HW_STATUS_NOT_CONTROLLABLE, "Not controllable")
      {
      }
  };

  class BitErrorException : public Exception
  {
    public:
      BitErrorException() :
        Exception(TIEPIE_HW_STATUS_BIT_ERROR, "Bit error")
      {
      }
  };

  class NoAcknowledgeException : public Exception
  {
    public:
      NoAcknowledgeException() :
        Exception(TIEPIE_HW_STATUS_NO_ACKNOWLEDGE, "No acknowledge")
      {
      }
  };

  class InvalidContainedDeviceSerialNumberException : public Exception
  {
    public:
      InvalidContainedDeviceSerialNumberException() :
        Exception(TIEPIE_HW_STATUS_INVALID_CONTAINED_DEVICE_SERIALNUMBER, "Invalid contained device serialnumber")
      {
      }
  };

  class InvalidInputException : public Exception
  {
    public:
      InvalidInputException() :
        Exception(TIEPIE_HW_STATUS_INVALID_INPUT, "Invalid input")
      {
      }
  };

  class InvalidOutputException : public Exception
  {
    public:
      InvalidOutputException() :
        Exception(TIEPIE_HW_STATUS_INVALID_OUTPUT, "Invalid output")
      {
      }
  };

  class NotAvailableException : public Exception
  {
    public:
      NotAvailableException() :
        Exception(TIEPIE_HW_STATUS_NOT_AVAILABLE, "Not available")
      {
      }
  };

  class InvalidFirmwareException : public Exception
  {
    public:
      InvalidFirmwareException() :
        Exception(TIEPIE_HW_STATUS_INVALID_FIRMWARE, "Invalid firmware")
      {
      }
  };

  class InvalidIndexException : public Exception
  {
    public:
      InvalidIndexException() :
        Exception(TIEPIE_HW_STATUS_INVALID_INDEX, "Invalid index")
      {
      }
  };

  class InvalidEepromException : public Exception
  {
    public:
      InvalidEepromException() :
        Exception(TIEPIE_HW_STATUS_INVALID_EEPROM, "Invalid eeprom")
      {
      }
  };

  class InitializationFailedException : public Exception
  {
    public:
      InitializationFailedException() :
        Exception(TIEPIE_HW_STATUS_INITIALIZATION_FAILED, "Initialization failed")
      {
      }
  };

  class LibraryNotInitializedException : public Exception
  {
    public:
      LibraryNotInitializedException() :
        Exception(TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED, "Library not initialized")
      {
      }
  };

  class NoTriggerEnabledException : public Exception
  {
    public:
      NoTriggerEnabledException() :
        Exception(TIEPIE_HW_STATUS_NO_TRIGGER_ENABLED, "No trigger enabled")
      {
      }
  };

  class SynchronizationFailedException : public Exception
  {
    public:
      SynchronizationFailedException() :
        Exception(TIEPIE_HW_STATUS_SYNCHRONIZATION_FAILED, "Synchronization failed")
      {
      }
  };

  class InvalidHS56CombinedDeviceException : public Exception
  {
    public:
      InvalidHS56CombinedDeviceException() :
        Exception(TIEPIE_HW_STATUS_INVALID_HS56_COMBINED_DEVICE, "Invalid hs56 combined device")
      {
      }
  };

  class MeasurementRunningException : public Exception
  {
    public:
      MeasurementRunningException() :
        Exception(TIEPIE_HW_STATUS_MEASUREMENT_RUNNING, "Measurement running")
      {
      }
  };

  class WirelesstriggermodulenotconnectedException : public Exception
  {
    public:
      WirelesstriggermodulenotconnectedException() :
        Exception(TIEPIE_HW_STATUS_WIRELESSTRIGGERMODULENOTCONNECTED, "Wirelesstriggermodulenotconnected")
      {
      }
  };

  class InitializationError10001Exception : public Exception
  {
    public:
      InitializationError10001Exception() :
        Exception(TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10001, "Initialization error 10001")
      {
      }
  };

  class InitializationError10002Exception : public Exception
  {
    public:
      InitializationError10002Exception() :
        Exception(TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10002, "Initialization error 10002")
      {
      }
  };

  class InitializationError10003Exception : public Exception
  {
    public:
      InitializationError10003Exception() :
        Exception(TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10003, "Initialization error 10003")
      {
      }
  };

  class InitializationError10004Exception : public Exception
  {
    public:
      InitializationError10004Exception() :
        Exception(TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10004, "Initialization error 10004")
      {
      }
  };

  class InitializationError10005Exception : public Exception
  {
    public:
      InitializationError10005Exception() :
        Exception(TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10005, "Initialization error 10005")
      {
      }
  };

  class InitializationError10006Exception : public Exception
  {
    public:
      InitializationError10006Exception() :
        Exception(TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10006, "Initialization error 10006")
      {
      }
  };

  class InitializationError10007Exception : public Exception
  {
    public:
      InitializationError10007Exception() :
        Exception(TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10007, "Initialization error 10007")
      {
      }
  };

  template<class T>
  class ObjectList
  {
    protected:
      std::vector<std::unique_ptr<T>> m_items;

    public:
      using size_type = typename std::vector<std::unique_ptr<T>>::size_type;

      ObjectList() = delete;
      ObjectList(const ObjectList&) = delete;
      ObjectList(ObjectList&&) = delete;
      ObjectList& operator=(const ObjectList&) = delete;
      ObjectList& operator=(ObjectList&&) = delete;

      ObjectList(Handle handle, size_type length)
      {
        for(size_type i = 0; i < length; i++)
          m_items.emplace_back(std::make_unique<T>(handle, i));
      }

      ObjectList(Handle handle, uint16_t ch, size_type length)
      {
        for(size_type i = 0; i < length; i++)
          m_items.emplace_back(std::make_unique<T>(handle, ch, i));
      }

      virtual ~ObjectList() = default;

      size_type count() const noexcept
      {
        return m_items.size();
      }

      auto begin() const noexcept
      {
        return m_items.begin();
      }

      auto end() const noexcept
      {
        return m_items.end();
      }

      auto cbegin() const noexcept
      {
        return m_items.cbegin();
      }

      auto cend() const noexcept
      {
        return m_items.cend();
      }

      auto rbegin() const noexcept
      {
        return m_items.rbegin();
      }

      auto rend() const noexcept
      {
        return m_items.rend();
      }

      auto crbegin() const noexcept
      {
        return m_items.crbegin();
      }

      auto crend() const noexcept
      {
        return m_items.crend();
      }

      const auto& at(size_type pos) const
      {
        return m_items.at(pos);
      }

      const auto& operator[](size_type pos) const
      {
        return m_items[pos];
      }
  };

  class Object;

  class Library
  {
    public:
      static void init()
      {
        tiepie_hw_init();
      }

      static bool isInitialized()
      {
        return tiepie_hw_is_initialized() != TIEPIE_HW_BOOL_FALSE;
      }

      static void fini()
      {
        tiepie_hw_fini();
      }

      static const tiepie_hw_version* version()
      {
        return tiepie_hw_get_version();
      }

      static std::vector<uint8_t> config()
      {
        const uint32_t length = tiepie_hw_get_config(nullptr, 0);
        std::vector<uint8_t> tmp(length);
        tiepie_hw_get_config(tmp.data(), length);
        return tmp;
      }

      static tiepie_hw_status lastStatus()
      {
        return tiepie_hw_get_last_status();
      }

      static std::string lastStatusStr()
      {
        const char* result = tiepie_hw_get_last_status_str();
        return result ? std::string(result) : std::string();
      }

      static void checkLastStatusAndThrowOnError()
      {
         tiepie_hw_status status = Library::lastStatus();

         if(status < 0) // Error's only.
           switch(status)
           {
             case TIEPIE_HW_STATUS_UNSUCCESSFUL:
               throw UnsuccessfulException();
             case TIEPIE_HW_STATUS_NOT_SUPPORTED:
               throw NotSupportedException();
             case TIEPIE_HW_STATUS_INVALID_HANDLE:
               throw InvalidHandleException();
             case TIEPIE_HW_STATUS_INVALID_VALUE:
               throw InvalidValueException();
             case TIEPIE_HW_STATUS_INVALID_CHANNEL:
               throw InvalidChannelException();
             case TIEPIE_HW_STATUS_INVALID_TRIGGER_SOURCE:
               throw InvalidTriggerSourceException();
             case TIEPIE_HW_STATUS_INVALID_DEVICE_TYPE:
               throw InvalidDeviceTypeException();
             case TIEPIE_HW_STATUS_INVALID_DEVICE_INDEX:
               throw InvalidDeviceIndexException();
             case TIEPIE_HW_STATUS_INVALID_PRODUCT_ID:
               throw InvalidProductIDException();
             case TIEPIE_HW_STATUS_INVALID_DEVICE_SERIALNUMBER:
               throw InvalidDeviceSerialNumberException();
             case TIEPIE_HW_STATUS_OBJECT_GONE:
               throw ObjectGoneException();
             case TIEPIE_HW_STATUS_INTERNAL_ADDRESS:
               throw InternalAddressException();
             case TIEPIE_HW_STATUS_NOT_CONTROLLABLE:
               throw NotControllableException();
             case TIEPIE_HW_STATUS_BIT_ERROR:
               throw BitErrorException();
             case TIEPIE_HW_STATUS_NO_ACKNOWLEDGE:
               throw NoAcknowledgeException();
             case TIEPIE_HW_STATUS_INVALID_CONTAINED_DEVICE_SERIALNUMBER:
               throw InvalidContainedDeviceSerialNumberException();
             case TIEPIE_HW_STATUS_INVALID_INPUT:
               throw InvalidInputException();
             case TIEPIE_HW_STATUS_INVALID_OUTPUT:
               throw InvalidOutputException();
             case TIEPIE_HW_STATUS_NOT_AVAILABLE:
               throw NotAvailableException();
             case TIEPIE_HW_STATUS_INVALID_FIRMWARE:
               throw InvalidFirmwareException();
             case TIEPIE_HW_STATUS_INVALID_INDEX:
               throw InvalidIndexException();
             case TIEPIE_HW_STATUS_INVALID_EEPROM:
               throw InvalidEepromException();
             case TIEPIE_HW_STATUS_INITIALIZATION_FAILED:
               throw InitializationFailedException();
             case TIEPIE_HW_STATUS_LIBRARY_NOT_INITIALIZED:
               throw LibraryNotInitializedException();
             case TIEPIE_HW_STATUS_NO_TRIGGER_ENABLED:
               throw NoTriggerEnabledException();
             case TIEPIE_HW_STATUS_SYNCHRONIZATION_FAILED:
               throw SynchronizationFailedException();
             case TIEPIE_HW_STATUS_INVALID_HS56_COMBINED_DEVICE:
               throw InvalidHS56CombinedDeviceException();
             case TIEPIE_HW_STATUS_MEASUREMENT_RUNNING:
               throw MeasurementRunningException();
             case TIEPIE_HW_STATUS_WIRELESSTRIGGERMODULENOTCONNECTED:
               throw WirelesstriggermodulenotconnectedException();
             case TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10001:
               throw InitializationError10001Exception();
             case TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10002:
               throw InitializationError10002Exception();
             case TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10003:
               throw InitializationError10003Exception();
             case TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10004:
               throw InitializationError10004Exception();
             case TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10005:
               throw InitializationError10005Exception();
             case TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10006:
               throw InitializationError10006Exception();
             case TIEPIE_HW_STATUS_INITIALIZATION_ERROR_10007:
               throw InitializationError10007Exception();
             default:
               throw Exception(status, Library::lastStatusStr());
           }
      }
  };

  class Object
  {
    protected:
      const Handle m_handle;

    public:
      Object() = delete;
      Object(const Object&) = delete;
      Object(Object&&) = delete;
      Object& operator=(const Object&) = delete;
      Object& operator=(Object&&) = delete;

      Object(Handle handle) :
        m_handle{handle}
      {
      }

      virtual ~Object()
      {
        tiepie_hw_object_close(m_handle);
      }

      Handle handle() const
      {
        return m_handle;
      }

      bool isRemoved() const
      {
        const bool result = tiepie_hw_object_is_removed(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t interfaces() const
      {
        const uint64_t result = tiepie_hw_object_get_interfaces(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void setEventCallback(tiepie_hw_event_callback callback, void* data)
      {
        tiepie_hw_object_set_event_callback(m_handle, callback, data);
        Library::checkLastStatusAndThrowOnError();
      }
  };

  class Device;
  class Oscilloscope;
  class Generator;

  class Server : public Object
  {
    public:
      Server(Handle handle) :
        Object{handle}
      {
      }

      bool connect(bool asynchronous)
      {
        const bool result = tiepie_hw_server_connect(m_handle, asynchronous ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool disconnect(bool force)
      {
        const bool result = tiepie_hw_server_disconnect(m_handle, force ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool remove(bool force)
      {
        const bool result = tiepie_hw_server_remove(m_handle, force ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t status() const
      {
        const uint32_t result = tiepie_hw_server_get_status(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t lastError() const
      {
        const uint32_t result = tiepie_hw_server_get_last_error(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::string url() const
      {
        const uint32_t length = tiepie_hw_server_get_url(m_handle, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_server_get_url(m_handle, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      std::string id() const
      {
        const uint32_t length = tiepie_hw_server_get_id(m_handle, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_server_get_id(m_handle, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      std::string ipAddress() const
      {
        const uint32_t length = tiepie_hw_server_get_ip_address(m_handle, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_server_get_ip_address(m_handle, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      uint16_t ipPort() const
      {
        const uint16_t result = tiepie_hw_server_get_ip_port(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::string name() const
      {
        const uint32_t length = tiepie_hw_server_get_name(m_handle, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_server_get_name(m_handle, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      std::string description() const
      {
        const uint32_t length = tiepie_hw_server_get_description(m_handle, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_server_get_description(m_handle, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      std::string version() const
      {
        const uint32_t length = tiepie_hw_server_get_version(m_handle, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_server_get_version(m_handle, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }
  };

  class Network
  {
    public:
      class Servers
      {
        public:
          [[nodiscard]] static std::unique_ptr<Server> add(const std::string& url)
          {
            Handle handle = TIEPIE_HW_HANDLE_INVALID;
            const bool result = tiepie_hw_network_servers_add(url.c_str(), TIEPIE_HW_STRING_LENGTH_NULL_TERMINATED, &handle);
            Library::checkLastStatusAndThrowOnError();
            return result ? std::make_unique<Server>(handle) : nullptr;
          }

          static bool remove(const std::string& url, bool force)
          {
            const bool result = tiepie_hw_network_servers_remove(url.c_str(), TIEPIE_HW_STRING_LENGTH_NULL_TERMINATED, force ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
            Library::checkLastStatusAndThrowOnError();
            return result;
          }

          static uint32_t count()
          {
            const uint32_t result = tiepie_hw_network_servers_get_count();
            Library::checkLastStatusAndThrowOnError();
            return result;
          }

          [[nodiscard]] static std::unique_ptr<Server> getByIndex(uint32_t index)
          {
            const Handle result = tiepie_hw_network_servers_get_by_index(index);
            Library::checkLastStatusAndThrowOnError();
            return std::make_unique<Server>(result);
          }

          [[nodiscard]] static std::unique_ptr<Server> getByUrl(const std::string& url)
          {
            const Handle result = tiepie_hw_network_servers_get_by_url(url.c_str(), TIEPIE_HW_STRING_LENGTH_NULL_TERMINATED);
            Library::checkLastStatusAndThrowOnError();
            return std::make_unique<Server>(result);
          }

          static void setCallbackAdded(tiepie_hw_handle_callback callback, void* data)
          {
            tiepie_hw_network_servers_set_callback_added(callback, data);
            Library::checkLastStatusAndThrowOnError();
          }
      };

      static bool autoDetectEnabled()
      {
        const bool result = tiepie_hw_network_get_auto_detect_enabled() != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      static bool setAutoDetectEnabled(bool value)
      {
        const bool result = tiepie_hw_network_set_auto_detect_enabled(value ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }
  };

  class TriggerInput;

  class TriggerInputs : public ObjectList<TriggerInput>
  {
    protected:
      const Handle m_handle;

    public:
      TriggerInputs(Handle handle, size_type length) :
        ObjectList<TriggerInput>(handle , length),
        m_handle(handle)
      {
      }

      const auto& getById(uint32_t id) const
      {
        const uint16_t index = tiepie_hw_device_trigger_get_input_index_by_id(m_handle, id);
        Library::checkLastStatusAndThrowOnError();
        return m_items.at(index);
      }
  };

  class TriggerOutput;

  class TriggerOutputs : public ObjectList<TriggerOutput>
  {
    protected:
      const Handle m_handle;

    public:
      TriggerOutputs(Handle handle, size_type length) :
        ObjectList<TriggerOutput>(handle, length),
        m_handle(handle)
      {
      }

      const auto& getById(uint32_t id) const
      {
        const uint16_t index = tiepie_hw_device_trigger_get_output_index_by_id(m_handle, id);
        Library::checkLastStatusAndThrowOnError();
        return m_items.at(index);
      }
  };

  class Device : public Object
  {
    public:
      const TriggerInputs triggerInputs;
      const TriggerOutputs triggerOutputs;

      Device(Handle handle) :
        Object{handle},
        triggerInputs{handle, tiepie_hw_device_trigger_get_input_count(handle)},
        triggerOutputs{handle, tiepie_hw_device_trigger_get_output_count(handle)}
      {
      }

      tiepie_hw_date calibrationDate() const
      {
        const tiepie_hw_date result = tiepie_hw_device_get_calibration_date(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t serialNumber() const
      {
        const uint32_t result = tiepie_hw_device_get_serial_number(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::string ipAddress() const
      {
        const uint32_t length = tiepie_hw_device_get_ip_address(m_handle, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_device_get_ip_address(m_handle, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      uint16_t ipPort() const
      {
        const uint16_t result = tiepie_hw_device_get_ip_port(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      tiepie_hw_productid productId() const
      {
        const tiepie_hw_productid result = tiepie_hw_device_get_product_id(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t type() const
      {
        const uint32_t result = tiepie_hw_device_get_type(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::string name() const
      {
        const uint32_t length = tiepie_hw_device_get_name(m_handle, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_device_get_name(m_handle, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      std::string nameShort() const
      {
        const uint32_t length = tiepie_hw_device_get_name_short(m_handle, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_device_get_name_short(m_handle, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      std::string nameShortest() const
      {
        const uint32_t length = tiepie_hw_device_get_name_shortest(m_handle, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_device_get_name_shortest(m_handle, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      bool hasWirelessTriggerModule() const
      {
        const bool result = tiepie_hw_device_has_wireless_trigger_module(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasBattery() const
      {
        const bool result = tiepie_hw_device_has_battery(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      int8_t batteryCharge() const
      {
        const int8_t result = tiepie_hw_device_get_battery_charge(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      int32_t batteryTimeToEmpty() const
      {
        const int32_t result = tiepie_hw_device_get_battery_time_to_empty(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      int32_t batteryTimeToFull() const
      {
        const int32_t result = tiepie_hw_device_get_battery_time_to_full(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isBatteryChargerConnected() const
      {
        const bool result = tiepie_hw_device_is_battery_charger_connected(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isBatteryCharging() const
      {
        const bool result = tiepie_hw_device_is_battery_charging(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isBatteryBroken() const
      {
        const bool result = tiepie_hw_device_is_battery_broken(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }
  };

  class TriggerInput
  {
    protected:
      const Handle m_handle;
      const uint16_t m_input;

    public:
      TriggerInput(Handle handle, uint16_t input) :
        m_handle(handle) ,
        m_input(input)
      {
      }

      bool isTriggered() const
      {
        const bool result = tiepie_hw_oscilloscope_trigger_input_is_triggered(m_handle, m_input) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool enabled() const
      {
        const bool result = tiepie_hw_device_trigger_input_get_enabled(m_handle, m_input) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool setEnabled(bool value)
      {
        const bool result = tiepie_hw_device_trigger_input_set_enabled(m_handle, m_input, value ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t kinds() const
      {
        const uint64_t result = tiepie_hw_device_trigger_input_get_kinds(m_handle, m_input);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getKinds(uint32_t measure_mode) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_trigger_input_get_kinds_ex(m_handle, m_input, measure_mode);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t kind() const
      {
        const uint64_t result = tiepie_hw_device_trigger_input_get_kind(m_handle, m_input);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t setKind(uint64_t value)
      {
        const uint64_t result = tiepie_hw_device_trigger_input_set_kind(m_handle, m_input, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isAvailable() const
      {
        const bool result = tiepie_hw_device_trigger_input_is_available(m_handle, m_input) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isAvailable(uint32_t measure_mode) const
      {
        const bool result = tiepie_hw_oscilloscope_trigger_input_is_available_ex(m_handle, m_input, measure_mode) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t id() const
      {
        const uint32_t result = tiepie_hw_device_trigger_input_get_id(m_handle, m_input);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::string name() const
      {
        const uint32_t length = tiepie_hw_device_trigger_input_get_name(m_handle , m_input, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_device_trigger_input_get_name(m_handle , m_input, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }
  };

  class TriggerOutput
  {
    protected:
      const Handle m_handle;
      const uint16_t m_output;

    public:
      TriggerOutput(Handle handle, uint16_t output) :
        m_handle{handle},
        m_output{output}
      {
      }

      bool enabled() const
      {
        const bool result = tiepie_hw_device_trigger_output_get_enabled(m_handle, m_output) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool setEnabled(bool value)
      {
        const bool result = tiepie_hw_device_trigger_output_set_enabled(m_handle, m_output, value ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t events() const
      {
        const uint64_t result = tiepie_hw_device_trigger_output_get_events(m_handle, m_output);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t event() const
      {
        const uint64_t result = tiepie_hw_device_trigger_output_get_event(m_handle, m_output);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t setEvent(uint64_t value)
      {
        const uint64_t result = tiepie_hw_device_trigger_output_set_event(m_handle, m_output, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t id() const
      {
        const uint32_t result = tiepie_hw_device_trigger_output_get_id(m_handle, m_output);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::string name() const
      {
        const uint32_t length = tiepie_hw_device_trigger_output_get_name(m_handle , m_output, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_device_trigger_output_get_name(m_handle , m_output, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      bool trigger()
      {
        const bool result = tiepie_hw_device_trigger_output_trigger(m_handle, m_output) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }
  };

  class OscilloscopeChannel;

  class OscilloscopeTrigger
  {
    protected:
      const Handle m_handle;

    public:
      OscilloscopeTrigger(Handle handle) :
        m_handle{handle}
      {
      }

      double timeout() const
      {
        const double result = tiepie_hw_oscilloscope_trigger_get_timeout(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setTimeout(double value)
      {
        const double result = tiepie_hw_oscilloscope_trigger_set_timeout(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyTimeout(double value) const
      {
        const double result = tiepie_hw_oscilloscope_trigger_verify_timeout(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyTimeout(double value, uint32_t measure_mode, double sample_rate) const
      {
        const double result = tiepie_hw_oscilloscope_trigger_verify_timeout_ex(m_handle, value, measure_mode, sample_rate);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasDelay() const
      {
        const bool result = tiepie_hw_oscilloscope_trigger_has_delay(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasDelay(uint32_t measure_mode) const
      {
        const bool result = tiepie_hw_oscilloscope_trigger_has_delay_ex(m_handle, measure_mode) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double delayMax() const
      {
        const double result = tiepie_hw_oscilloscope_trigger_get_delay_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double delayMax(uint32_t measure_mode, double sample_rate) const
      {
        const double result = tiepie_hw_oscilloscope_trigger_get_delay_max_ex(m_handle, measure_mode, sample_rate);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double delay() const
      {
        const double result = tiepie_hw_oscilloscope_trigger_get_delay(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setDelay(double value)
      {
        const double result = tiepie_hw_oscilloscope_trigger_set_delay(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyDelay(double value) const
      {
        const double result = tiepie_hw_oscilloscope_trigger_verify_delay(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyDelay(double value, uint32_t measure_mode, double sample_rate) const
      {
        const double result = tiepie_hw_oscilloscope_trigger_verify_delay_ex(m_handle, value, measure_mode, sample_rate);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }
  };

  class Oscilloscope : public Device
  {
    public:
      using Channels = ObjectList<OscilloscopeChannel>;

      const Channels channels;
      const std::unique_ptr<OscilloscopeTrigger> trigger;

      Oscilloscope(Handle handle) :
        Device{handle},
        channels{handle, tiepie_hw_oscilloscope_get_channel_count(handle)},
        trigger{tiepie_hw_oscilloscope_has_trigger(handle) ? std::make_unique<OscilloscopeTrigger>(handle) : nullptr}
      {
      }

      bool isDemo() const
      {
        const bool result = tiepie_hw_oscilloscope_is_demo(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getData(float** buffers, uint16_t channel_count, uint64_t start_index, uint64_t sample_count)
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data(m_handle, buffers, channel_count, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getData1ch(float* buffer_ch1, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_1ch(m_handle, buffer_ch1, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getData2ch(float* buffer_ch1, float* buffer_ch2, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_2ch(m_handle, buffer_ch1, buffer_ch2, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getData3ch(float* buffer_ch1, float* buffer_ch2, float* buffer_ch3, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_3ch(m_handle, buffer_ch1, buffer_ch2, buffer_ch3, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getData4ch(float* buffer_ch1, float* buffer_ch2, float* buffer_ch3, float* buffer_ch4, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_4ch(m_handle, buffer_ch1, buffer_ch2, buffer_ch3, buffer_ch4, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getData5ch(float* buffer_ch1, float* buffer_ch2, float* buffer_ch3, float* buffer_ch4, float* buffer_ch5, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_5ch(m_handle, buffer_ch1, buffer_ch2, buffer_ch3, buffer_ch4, buffer_ch5, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getData6ch(float* buffer_ch1, float* buffer_ch2, float* buffer_ch3, float* buffer_ch4, float* buffer_ch5, float* buffer_ch6, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_6ch(m_handle, buffer_ch1, buffer_ch2, buffer_ch3, buffer_ch4, buffer_ch5, buffer_ch6, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getData7ch(float* buffer_ch1, float* buffer_ch2, float* buffer_ch3, float* buffer_ch4, float* buffer_ch5, float* buffer_ch6, float* buffer_ch7, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_7ch(m_handle, buffer_ch1, buffer_ch2, buffer_ch3, buffer_ch4, buffer_ch5, buffer_ch6, buffer_ch7, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getData8ch(float* buffer_ch1, float* buffer_ch2, float* buffer_ch3, float* buffer_ch4, float* buffer_ch5, float* buffer_ch6, float* buffer_ch7, float* buffer_ch8, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_8ch(m_handle, buffer_ch1, buffer_ch2, buffer_ch3, buffer_ch4, buffer_ch5, buffer_ch6, buffer_ch7, buffer_ch8, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t validPreSampleCount() const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_valid_pre_sample_count(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getDataRaw(void** buffers, uint16_t channel_count, uint64_t start_index, uint64_t sample_count)
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_raw(m_handle, buffers, channel_count, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getDataRaw1ch(void* buffer_ch1, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_raw_1ch(m_handle, buffer_ch1, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getDataRaw2ch(void* buffer_ch1, void* buffer_ch2, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_raw_2ch(m_handle, buffer_ch1, buffer_ch2, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getDataRaw3ch(void* buffer_ch1, void* buffer_ch2, void* buffer_ch3, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_raw_3ch(m_handle, buffer_ch1, buffer_ch2, buffer_ch3, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getDataRaw4ch(void* buffer_ch1, void* buffer_ch2, void* buffer_ch3, void* buffer_ch4, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_raw_4ch(m_handle, buffer_ch1, buffer_ch2, buffer_ch3, buffer_ch4, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getDataRaw5ch(void* buffer_ch1, void* buffer_ch2, void* buffer_ch3, void* buffer_ch4, void* buffer_ch5, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_raw_5ch(m_handle, buffer_ch1, buffer_ch2, buffer_ch3, buffer_ch4, buffer_ch5, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getDataRaw6ch(void* buffer_ch1, void* buffer_ch2, void* buffer_ch3, void* buffer_ch4, void* buffer_ch5, void* buffer_ch6, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_raw_6ch(m_handle, buffer_ch1, buffer_ch2, buffer_ch3, buffer_ch4, buffer_ch5, buffer_ch6, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getDataRaw7ch(void* buffer_ch1, void* buffer_ch2, void* buffer_ch3, void* buffer_ch4, void* buffer_ch5, void* buffer_ch6, void* buffer_ch7, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_raw_7ch(m_handle, buffer_ch1, buffer_ch2, buffer_ch3, buffer_ch4, buffer_ch5, buffer_ch6, buffer_ch7, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t getDataRaw8ch(void* buffer_ch1, void* buffer_ch2, void* buffer_ch3, void* buffer_ch4, void* buffer_ch5, void* buffer_ch6, void* buffer_ch7, void* buffer_ch8, uint64_t start_index, uint64_t sample_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_data_raw_8ch(m_handle, buffer_ch1, buffer_ch2, buffer_ch3, buffer_ch4, buffer_ch5, buffer_ch6, buffer_ch7, buffer_ch8, start_index, sample_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void start()
      {
        tiepie_hw_oscilloscope_start(m_handle);
        Library::checkLastStatusAndThrowOnError();
      }

      void stop()
      {
        tiepie_hw_oscilloscope_stop(m_handle);
        Library::checkLastStatusAndThrowOnError();
      }

      void forceTrigger()
      {
        tiepie_hw_oscilloscope_force_trigger(m_handle);
        Library::checkLastStatusAndThrowOnError();
      }

      uint32_t measureModes() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_get_measure_modes(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t measureMode() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_get_measure_mode(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t setMeasureMode(uint32_t value)
      {
        const uint32_t result = tiepie_hw_oscilloscope_set_measure_mode(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isRunning() const
      {
        const bool result = tiepie_hw_oscilloscope_is_running(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isTriggered() const
      {
        const bool result = tiepie_hw_oscilloscope_is_triggered(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isTimeoutTriggered() const
      {
        const bool result = tiepie_hw_oscilloscope_is_timeout_triggered(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isForceTriggered() const
      {
        const bool result = tiepie_hw_oscilloscope_is_force_triggered(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isDataReady() const
      {
        const bool result = tiepie_hw_oscilloscope_is_data_ready(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isDataOverflow() const
      {
        const bool result = tiepie_hw_oscilloscope_is_data_overflow(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t autoResolutionModes() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_get_auto_resolution_modes(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t autoResolutionMode() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_get_auto_resolution_mode(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t setAutoResolutionMode(uint32_t value)
      {
        const uint32_t result = tiepie_hw_oscilloscope_set_auto_resolution_mode(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::vector<uint8_t> resolutions() const
      {
        const uint32_t length = tiepie_hw_oscilloscope_get_resolutions(m_handle, nullptr, 0);
        Library::checkLastStatusAndThrowOnError();
        std::vector<uint8_t> tmp(length);
        tiepie_hw_oscilloscope_get_resolutions(m_handle, tmp.data(), length);
        Library::checkLastStatusAndThrowOnError();
        return tmp;
      }

      uint8_t resolution() const
      {
        const uint8_t result = tiepie_hw_oscilloscope_get_resolution(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint8_t setResolution(uint8_t value)
      {
        const uint8_t result = tiepie_hw_oscilloscope_set_resolution(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isResolutionEnhanced() const
      {
        const bool result = tiepie_hw_oscilloscope_is_resolution_enhanced(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isResolutionEnhanced(uint8_t value) const
      {
        const bool result = tiepie_hw_oscilloscope_is_resolution_enhanced_ex(m_handle, value) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t clockSources() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_get_clock_sources(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t clockSource() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_get_clock_source(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t setClockSource(uint32_t value)
      {
        const uint32_t result = tiepie_hw_oscilloscope_set_clock_source(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::vector<double> clockSourceFrequencies() const
      {
        const uint32_t length = tiepie_hw_oscilloscope_get_clock_source_frequencies(m_handle, nullptr, 0);
        Library::checkLastStatusAndThrowOnError();
        std::vector<double> tmp(length);
        tiepie_hw_oscilloscope_get_clock_source_frequencies(m_handle, tmp.data(), length);
        Library::checkLastStatusAndThrowOnError();
        return tmp;
      }

      std::vector<double> getClockSourceFrequencies(uint32_t value) const
      {
        const uint32_t length = tiepie_hw_oscilloscope_get_clock_source_frequencies_ex(m_handle, value, nullptr, 0);
        Library::checkLastStatusAndThrowOnError();
        std::vector<double> tmp(length);
        tiepie_hw_oscilloscope_get_clock_source_frequencies_ex(m_handle, value, tmp.data(), length);
        Library::checkLastStatusAndThrowOnError();
        return tmp;
      }

      double clockSourceFrequency() const
      {
        const double result = tiepie_hw_oscilloscope_get_clock_source_frequency(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setClockSourceFrequency(double value)
      {
        const double result = tiepie_hw_oscilloscope_set_clock_source_frequency(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t clockOutputs() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_get_clock_outputs(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t clockOutput() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_get_clock_output(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t setClockOutput(uint32_t value)
      {
        const uint32_t result = tiepie_hw_oscilloscope_set_clock_output(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::vector<double> clockOutputFrequencies() const
      {
        const uint32_t length = tiepie_hw_oscilloscope_get_clock_output_frequencies(m_handle, nullptr, 0);
        Library::checkLastStatusAndThrowOnError();
        std::vector<double> tmp(length);
        tiepie_hw_oscilloscope_get_clock_output_frequencies(m_handle, tmp.data(), length);
        Library::checkLastStatusAndThrowOnError();
        return tmp;
      }

      std::vector<double> getClockOutputFrequencies(uint32_t clock_output) const
      {
        const uint32_t length = tiepie_hw_oscilloscope_get_clock_output_frequencies_ex(m_handle, clock_output, nullptr, 0);
        Library::checkLastStatusAndThrowOnError();
        std::vector<double> tmp(length);
        tiepie_hw_oscilloscope_get_clock_output_frequencies_ex(m_handle, clock_output, tmp.data(), length);
        Library::checkLastStatusAndThrowOnError();
        return tmp;
      }

      double clockOutputFrequency() const
      {
        const double result = tiepie_hw_oscilloscope_get_clock_output_frequency(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setClockOutputFrequency(double value)
      {
        const double result = tiepie_hw_oscilloscope_set_clock_output_frequency(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double sampleRateMax() const
      {
        const double result = tiepie_hw_oscilloscope_get_sample_rate_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double sampleRate() const
      {
        const double result = tiepie_hw_oscilloscope_get_sample_rate(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setSampleRate(double value)
      {
        const double result = tiepie_hw_oscilloscope_set_sample_rate(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifySampleRate(double value) const
      {
        const double result = tiepie_hw_oscilloscope_verify_sample_rate(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifySampleRate(double value, uint32_t measure_mode, uint8_t resolution, const tiepie_hw_bool* channel_enabled, uint16_t channel_count) const
      {
        const double result = tiepie_hw_oscilloscope_verify_sample_rate_ex(m_handle, value, measure_mode, resolution, channel_enabled, channel_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void verifySampleRates(double* values, uint32_t count, uint32_t measure_mode, uint32_t auto_resolution_mode, uint8_t resolution, const tiepie_hw_bool* channel_enabled, uint16_t channel_count) const
      {
        tiepie_hw_oscilloscope_verify_sample_rates_ex(m_handle, values, count, measure_mode, auto_resolution_mode, resolution, channel_enabled, channel_count);
        Library::checkLastStatusAndThrowOnError();
      }

      uint64_t recordLengthMax() const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_record_length_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t recordLengthMax(uint32_t measure_mode, uint8_t resolution) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_record_length_max_ex(m_handle, measure_mode, resolution);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t recordLength() const
      {
        const uint64_t result = tiepie_hw_oscilloscope_get_record_length(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t setRecordLength(uint64_t record_length)
      {
        const uint64_t result = tiepie_hw_oscilloscope_set_record_length(m_handle, record_length);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t verifyRecordLength(uint64_t record_length) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_verify_record_length(m_handle, record_length);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t verifyRecordLength(uint64_t record_length, uint32_t measure_mode, uint8_t resolution, const tiepie_hw_bool* channel_enabled, uint16_t channel_count) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_verify_record_length_ex(m_handle, record_length, measure_mode, resolution, channel_enabled, channel_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double preSampleRatio() const
      {
        const double result = tiepie_hw_oscilloscope_get_pre_sample_ratio(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setPreSampleRatio(double value)
      {
        const double result = tiepie_hw_oscilloscope_set_pre_sample_ratio(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t segmentCountMax() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_get_segment_count_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t segmentCountMax(uint32_t measure_mode) const
      {
        const uint32_t result = tiepie_hw_oscilloscope_get_segment_count_max_ex(m_handle, measure_mode);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t segmentCount() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_get_segment_count(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t setSegmentCount(uint32_t value)
      {
        const uint32_t result = tiepie_hw_oscilloscope_set_segment_count(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t verifySegmentCount(uint32_t value) const
      {
        const uint32_t result = tiepie_hw_oscilloscope_verify_segment_count(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t verifySegmentCount(uint32_t value, uint32_t measure_mode, uint64_t record_length, const tiepie_hw_bool* channel_enabled, uint16_t channel_count) const
      {
        const uint32_t result = tiepie_hw_oscilloscope_verify_segment_count_ex(m_handle, value, measure_mode, record_length, channel_enabled, channel_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasTrigger() const
      {
        const bool result = tiepie_hw_oscilloscope_has_trigger(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasTrigger(uint32_t measure_mode) const
      {
        const bool result = tiepie_hw_oscilloscope_has_trigger_ex(m_handle, measure_mode) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasPresamplesValid() const
      {
        const bool result = tiepie_hw_oscilloscope_has_presamples_valid(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasPresamplesValid(uint32_t measure_mode) const
      {
        const bool result = tiepie_hw_oscilloscope_has_presamples_valid_ex(m_handle, measure_mode) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool presamplesValid() const
      {
        const bool result = tiepie_hw_oscilloscope_get_presamples_valid(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool setPresamplesValid(bool value)
      {
        const bool result = tiepie_hw_oscilloscope_set_presamples_valid(m_handle, value ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasSureconnect() const
      {
        const bool result = tiepie_hw_oscilloscope_has_sureconnect(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void startSureconnect()
      {
        tiepie_hw_oscilloscope_start_sureconnect(m_handle);
        Library::checkLastStatusAndThrowOnError();
      }

      void startSureconnect(const tiepie_hw_bool* channel_enabled, uint16_t channel_count)
      {
        tiepie_hw_oscilloscope_start_sureconnect_ex(m_handle, channel_enabled, channel_count);
        Library::checkLastStatusAndThrowOnError();
      }

      bool isSureconnectCompleted() const
      {
        const bool result = tiepie_hw_oscilloscope_is_sureconnect_completed(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint16_t sureconnectData(tiepie_hw_tristate* buffer, uint16_t channel_count) const
      {
        const uint16_t result = tiepie_hw_oscilloscope_get_sureconnect_data(m_handle, buffer, channel_count);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }
  };

  class OscilloscopeChannelTriggerLevel
  {
    protected:
      const Handle m_handle;
      const uint16_t m_ch;
      const uint32_t m_index;

    public:
      OscilloscopeChannelTriggerLevel() = delete;
      OscilloscopeChannelTriggerLevel(Handle handle, uint16_t ch, uint32_t index) :
        m_handle{handle},
        m_ch{ch},
        m_index{index}
      {
      }
      OscilloscopeChannelTriggerLevel(const OscilloscopeChannelTriggerLevel&) = delete;
      OscilloscopeChannelTriggerLevel(OscilloscopeChannelTriggerLevel&&) = delete;
      OscilloscopeChannelTriggerLevel& operator=(const OscilloscopeChannelTriggerLevel&) = delete;
      OscilloscopeChannelTriggerLevel& operator=(OscilloscopeChannelTriggerLevel&&) = delete;

      operator double() const
      {
        const double result = tiepie_hw_oscilloscope_channel_trigger_get_level(m_handle, m_ch, m_index);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      OscilloscopeChannelTriggerLevel& operator=(double value)
      {
        tiepie_hw_oscilloscope_channel_trigger_set_level(m_handle, m_ch, m_index, value);
        Library::checkLastStatusAndThrowOnError();
        return *this;
      }
  };

  class OscilloscopeChannelTriggerLevels : public ObjectList<OscilloscopeChannelTriggerLevel>
  {
    protected:
      const Handle m_handle;
      const uint16_t m_ch;

    public:
      OscilloscopeChannelTriggerLevels() = delete;
      OscilloscopeChannelTriggerLevels(Handle handle, uint16_t ch) :
        ObjectList<OscilloscopeChannelTriggerLevel>(handle, ch, 2) ,
        m_handle( handle ) ,
        m_ch( ch )
      {
      }
      OscilloscopeChannelTriggerLevels(const OscilloscopeChannelTriggerLevels&) = delete;
      OscilloscopeChannelTriggerLevels(OscilloscopeChannelTriggerLevels&&) = delete;
      OscilloscopeChannelTriggerLevels& operator=(const OscilloscopeChannelTriggerLevels&) = delete;
      OscilloscopeChannelTriggerLevels& operator=(OscilloscopeChannelTriggerLevels&&) = delete;

      size_type count() const
      {
        const size_type result = tiepie_hw_oscilloscope_channel_trigger_get_level_count(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }
  };

  class OscilloscopeChannelTriggerHysteresis
  {
    protected:
      const Handle m_handle;
      const uint16_t m_ch;
      const uint32_t m_index;

    public:
      OscilloscopeChannelTriggerHysteresis() = delete;
      OscilloscopeChannelTriggerHysteresis(Handle handle, uint16_t ch, uint32_t index) :
        m_handle{handle},
        m_ch{ch},
        m_index{index}
      {
      }
      OscilloscopeChannelTriggerHysteresis(const OscilloscopeChannelTriggerHysteresis&) = delete;
      OscilloscopeChannelTriggerHysteresis(OscilloscopeChannelTriggerHysteresis&&) = delete;
      OscilloscopeChannelTriggerHysteresis& operator=(const OscilloscopeChannelTriggerHysteresis&) = delete;
      OscilloscopeChannelTriggerHysteresis& operator=(OscilloscopeChannelTriggerHysteresis&&) = delete;

      operator double() const
      {
        const double result = tiepie_hw_oscilloscope_channel_trigger_get_hysteresis(m_handle, m_ch, m_index);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      OscilloscopeChannelTriggerHysteresis& operator=(double value)
      {
        tiepie_hw_oscilloscope_channel_trigger_set_hysteresis(m_handle, m_ch, m_index, value);
        Library::checkLastStatusAndThrowOnError();
        return *this;
      }
  };

  class OscilloscopeChannelTriggerHystereses : public ObjectList<OscilloscopeChannelTriggerHysteresis>
  {
    protected:
      const Handle m_handle;
      const uint16_t m_ch;

    public:
      OscilloscopeChannelTriggerHystereses() = delete;
      OscilloscopeChannelTriggerHystereses(Handle handle, uint16_t ch) :
        ObjectList<OscilloscopeChannelTriggerHysteresis>(handle, ch, 2) ,
        m_handle( handle ) ,
        m_ch( ch )
      {
      }
      OscilloscopeChannelTriggerHystereses(const OscilloscopeChannelTriggerHystereses&) = delete;
      OscilloscopeChannelTriggerHystereses(OscilloscopeChannelTriggerHystereses&&) = delete;
      OscilloscopeChannelTriggerHystereses& operator=(const OscilloscopeChannelTriggerHystereses&) = delete;
      OscilloscopeChannelTriggerHystereses& operator=(OscilloscopeChannelTriggerHystereses&&) = delete;

      size_type count() const
      {
        const size_type result = tiepie_hw_oscilloscope_channel_trigger_get_hysteresis_count(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }
  };

  class OscilloscopeChannelTriggerTime
  {
    protected:
      const Handle m_handle;
      const uint16_t m_ch;
      const uint32_t m_index;

    public:
      OscilloscopeChannelTriggerTime() = delete;
      OscilloscopeChannelTriggerTime(Handle handle, uint16_t ch, uint32_t index) :
        m_handle{handle},
        m_ch{ch},
        m_index{index}
      {
      }
      OscilloscopeChannelTriggerTime(const OscilloscopeChannelTriggerTime&) = delete;
      OscilloscopeChannelTriggerTime(OscilloscopeChannelTriggerTime&&) = delete;
      OscilloscopeChannelTriggerTime& operator=(const OscilloscopeChannelTriggerTime&) = delete;
      OscilloscopeChannelTriggerTime& operator=(OscilloscopeChannelTriggerTime&&) = delete;

      operator double() const
      {
        const double result = tiepie_hw_oscilloscope_channel_trigger_get_time(m_handle, m_ch, m_index);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      OscilloscopeChannelTriggerTime& operator=(double value)
      {
        tiepie_hw_oscilloscope_channel_trigger_set_time(m_handle, m_ch, m_index, value);
        Library::checkLastStatusAndThrowOnError();
        return *this;
      }

      double verify(double value) const
      {
        const double result = tiepie_hw_oscilloscope_channel_trigger_verify_time(m_handle, m_ch, m_index, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verify(double value, uint32_t measure_mode, double sample_rate, uint64_t trigger_kind, uint32_t trigger_condition) const
      {
        const double result = tiepie_hw_oscilloscope_channel_trigger_verify_time_ex(m_handle, m_ch, m_index, value, measure_mode, sample_rate, trigger_kind, trigger_condition);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }
  };

  class OscilloscopeChannelTriggerTimes : public ObjectList<OscilloscopeChannelTriggerTime>
  {
    protected:
      const Handle m_handle;
      const uint16_t m_ch;

    public:
      OscilloscopeChannelTriggerTimes() = delete;
      OscilloscopeChannelTriggerTimes(Handle handle, uint16_t ch) :
        ObjectList<OscilloscopeChannelTriggerTime>(handle, ch, 2) ,
        m_handle( handle ) ,
        m_ch( ch )
      {
      }
      OscilloscopeChannelTriggerTimes(const OscilloscopeChannelTriggerTimes&) = delete;
      OscilloscopeChannelTriggerTimes(OscilloscopeChannelTriggerTimes&&) = delete;
      OscilloscopeChannelTriggerTimes& operator=(const OscilloscopeChannelTriggerTimes&) = delete;
      OscilloscopeChannelTriggerTimes& operator=(OscilloscopeChannelTriggerTimes&&) = delete;

      size_type count() const
      {
        const size_type result = tiepie_hw_oscilloscope_channel_trigger_get_time_count(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }
  };

  class OscilloscopeChannelTrigger
  {
    protected:
      const Handle m_handle;
      const uint16_t m_ch;

    public:
      const OscilloscopeChannelTriggerLevels levels;
      const OscilloscopeChannelTriggerHystereses hystereses;
      const OscilloscopeChannelTriggerTimes times;

      OscilloscopeChannelTrigger(Handle handle, uint16_t ch) :
        m_handle{handle},
        m_ch{ch},
        levels{handle, ch},
        hystereses{handle, ch},
        times{handle, ch}
      {
      }

      bool isAvailable() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_trigger_is_available(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isAvailable(uint32_t measure_mode, double sample_rate, uint8_t resolution, const tiepie_hw_bool* channel_enabled, const tiepie_hw_bool* channel_trigger_enabled, uint16_t channel_count) const
      {
        const bool result = tiepie_hw_oscilloscope_channel_trigger_is_available_ex(m_handle, m_ch, measure_mode, sample_rate, resolution, channel_enabled, channel_trigger_enabled, channel_count) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isTriggered() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_trigger_is_triggered(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool enabled() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_trigger_get_enabled(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool setEnabled(bool value)
      {
        const bool result = tiepie_hw_oscilloscope_channel_trigger_set_enabled(m_handle, m_ch, value ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t kinds() const
      {
        const uint64_t result = tiepie_hw_oscilloscope_channel_trigger_get_kinds(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t kinds(uint32_t measure_mode) const
      {
        const uint64_t result = tiepie_hw_oscilloscope_channel_trigger_get_kinds_ex(m_handle, m_ch, measure_mode);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t kind() const
      {
        const uint64_t result = tiepie_hw_oscilloscope_channel_trigger_get_kind(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t setKind(uint64_t value)
      {
        const uint64_t result = tiepie_hw_oscilloscope_channel_trigger_set_kind(m_handle, m_ch, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t levelModes() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_channel_trigger_get_level_modes(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t levelMode() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_channel_trigger_get_level_mode(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t setLevelMode(uint32_t value)
      {
        const uint32_t result = tiepie_hw_oscilloscope_channel_trigger_set_level_mode(m_handle, m_ch, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t conditions() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_channel_trigger_get_conditions(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t conditions(uint32_t measure_mode, uint64_t trigger_kind) const
      {
        const uint32_t result = tiepie_hw_oscilloscope_channel_trigger_get_conditions_ex(m_handle, m_ch, measure_mode, trigger_kind);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t condition() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_channel_trigger_get_condition(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t setCondition(uint32_t value)
      {
        const uint32_t result = tiepie_hw_oscilloscope_channel_trigger_set_condition(m_handle, m_ch, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }
  };

  class OscilloscopeChannelDemo
  {
    protected:
      const Handle m_handle;
      const uint16_t m_ch;

    public:
      OscilloscopeChannelDemo(Handle handle, uint16_t ch) :
        m_handle(handle),
        m_ch(ch)
      {
      }

      tiepie_hw_demosignal signal() const
      {
        const tiepie_hw_demosignal result = tiepie_hw_oscilloscope_channel_demo_get_signal(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      tiepie_hw_demosignal setSignal(tiepie_hw_demosignal value)
      {
        const tiepie_hw_demosignal result = tiepie_hw_oscilloscope_channel_demo_set_signal(m_handle, m_ch, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasAmplitude() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_demo_has_amplitude(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double amplitude() const
      {
        const double result = tiepie_hw_oscilloscope_channel_demo_get_amplitude(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setAmplitude(double value)
      {
        const double result = tiepie_hw_oscilloscope_channel_demo_set_amplitude(m_handle, m_ch, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasFrequency() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_demo_has_frequency(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double frequency() const
      {
        const double result = tiepie_hw_oscilloscope_channel_demo_get_frequency(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setFrequency(double value)
      {
        const double result = tiepie_hw_oscilloscope_channel_demo_set_frequency(m_handle, m_ch, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasOffset() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_demo_has_offset(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double offset() const
      {
        const double result = tiepie_hw_oscilloscope_channel_demo_get_offset(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setOffset(double value)
      {
        const double result = tiepie_hw_oscilloscope_channel_demo_set_offset(m_handle, m_ch, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasSymmetry() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_demo_has_symmetry(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double symmetry() const
      {
        const double result = tiepie_hw_oscilloscope_channel_demo_get_symmetry(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setSymmetry(double value)
      {
        const double result = tiepie_hw_oscilloscope_channel_demo_set_symmetry(m_handle, m_ch, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasPhase() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_demo_has_phase(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double phase() const
      {
        const double result = tiepie_hw_oscilloscope_channel_demo_get_phase(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setPhase(double value)
      {
        const double result = tiepie_hw_oscilloscope_channel_demo_set_phase(m_handle, m_ch, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasNoiseEnabled() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_demo_has_noise_enabled(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool noiseEnabled() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_demo_get_noise_enabled(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool setNoiseEnabled(bool value)
      {
        const bool result = tiepie_hw_oscilloscope_channel_demo_set_noise_enabled(m_handle, m_ch, value ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }
  };

  class OscilloscopeChannel
  {
    protected:
      const Handle m_handle;
      const uint16_t m_ch;

    public:
      const std::unique_ptr<OscilloscopeChannelTrigger> trigger;
      const std::unique_ptr<OscilloscopeChannelDemo> demo;

      OscilloscopeChannel(Handle handle, uint16_t ch) :
        m_handle{handle},
        m_ch{ch},
        trigger{tiepie_hw_oscilloscope_channel_has_trigger(handle, ch) ? std::make_unique<OscilloscopeChannelTrigger>(handle, ch) : nullptr},
        demo{tiepie_hw_oscilloscope_is_demo(handle) ? std::make_unique<OscilloscopeChannelDemo>(handle, ch) : nullptr}
      {
      }

      uint32_t number() const
      {
        return m_ch + 1;
      }

      bool isAvailable() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_is_available(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isAvailable(uint32_t measure_mode, double sample_rate, uint8_t resolution, const tiepie_hw_bool* channel_enabled, uint16_t channel_count) const
      {
        const bool result = tiepie_hw_oscilloscope_channel_is_available_ex(m_handle, m_ch, measure_mode, sample_rate, resolution, channel_enabled, channel_count) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t connectorType() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_channel_get_connector_type(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isDifferential() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_is_differential(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isIsolated() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_is_isolated(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double impedance() const
      {
        const double result = tiepie_hw_oscilloscope_channel_get_impedance(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::vector<double> bandwidths() const
      {
        const uint32_t length = tiepie_hw_oscilloscope_channel_get_bandwidths(m_handle, m_ch, nullptr, 0);
        Library::checkLastStatusAndThrowOnError();
        std::vector<double> tmp(length);
        tiepie_hw_oscilloscope_channel_get_bandwidths(m_handle, m_ch, tmp.data(), length);
        Library::checkLastStatusAndThrowOnError();
        return tmp;
      }

      double bandwidth() const
      {
        const double result = tiepie_hw_oscilloscope_channel_get_bandwidth(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setBandwidth(double bandwidth)
      {
        const double result = tiepie_hw_oscilloscope_channel_set_bandwidth(m_handle, m_ch, bandwidth);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t couplings() const
      {
        const uint64_t result = tiepie_hw_oscilloscope_channel_get_couplings(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t coupling() const
      {
        const uint64_t result = tiepie_hw_oscilloscope_channel_get_coupling(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t setCoupling(uint64_t coupling)
      {
        const uint64_t result = tiepie_hw_oscilloscope_channel_set_coupling(m_handle, m_ch, coupling);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool enabled() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_get_enabled(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool setEnabled(bool value)
      {
        const bool result = tiepie_hw_oscilloscope_channel_set_enabled(m_handle, m_ch, value ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool autoRanging() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_get_auto_ranging(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool setAutoRanging(bool value)
      {
        const bool result = tiepie_hw_oscilloscope_channel_set_auto_ranging(m_handle, m_ch, value ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::vector<double> ranges() const
      {
        const uint32_t length = tiepie_hw_oscilloscope_channel_get_ranges(m_handle, m_ch, nullptr, 0);
        Library::checkLastStatusAndThrowOnError();
        std::vector<double> tmp(length);
        tiepie_hw_oscilloscope_channel_get_ranges(m_handle, m_ch, tmp.data(), length);
        Library::checkLastStatusAndThrowOnError();
        return tmp;
      }

      std::vector<double> ranges(uint64_t coupling) const
      {
        const uint32_t length = tiepie_hw_oscilloscope_channel_get_ranges_ex(m_handle, m_ch, coupling, nullptr, 0);
        Library::checkLastStatusAndThrowOnError();
        std::vector<double> tmp(length);
        tiepie_hw_oscilloscope_channel_get_ranges_ex(m_handle, m_ch, coupling, tmp.data(), length);
        Library::checkLastStatusAndThrowOnError();
        return tmp;
      }

      double range() const
      {
        const double result = tiepie_hw_oscilloscope_channel_get_range(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setRange(double range)
      {
        const double result = tiepie_hw_oscilloscope_channel_set_range(m_handle, m_ch, range);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasSafeground() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_has_safeground(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool safegroundEnabled() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_get_safeground_enabled(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool setSafegroundEnabled(bool value)
      {
        const bool result = tiepie_hw_oscilloscope_channel_set_safeground_enabled(m_handle, m_ch, value ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double safegroundThresholdMin() const
      {
        const double result = tiepie_hw_oscilloscope_channel_get_safeground_threshold_min(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double safegroundThresholdMax() const
      {
        const double result = tiepie_hw_oscilloscope_channel_get_safeground_threshold_max(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double safegroundThreshold() const
      {
        const double result = tiepie_hw_oscilloscope_channel_get_safeground_threshold(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setSafegroundThreshold(double threshold)
      {
        const double result = tiepie_hw_oscilloscope_channel_set_safeground_threshold(m_handle, m_ch, threshold);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifySafegroundThreshold(double threshold) const
      {
        const double result = tiepie_hw_oscilloscope_channel_verify_safeground_threshold(m_handle, m_ch, threshold);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasTrigger() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_has_trigger(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasTrigger(uint32_t measure_mode) const
      {
        const bool result = tiepie_hw_oscilloscope_channel_has_trigger_ex(m_handle, m_ch, measure_mode) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void getDataValueRange(double* min, double* max) const
      {
        tiepie_hw_oscilloscope_channel_get_data_value_range(m_handle, m_ch, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      double dataValueMin() const
      {
        const double result = tiepie_hw_oscilloscope_channel_get_data_value_min(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double dataValueMax() const
      {
        const double result = tiepie_hw_oscilloscope_channel_get_data_value_max(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t dataRawType() const
      {
        const uint32_t result = tiepie_hw_oscilloscope_channel_get_data_raw_type(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void getDataRawValueRange(int64_t* min, int64_t* zero, int64_t* max) const
      {
        tiepie_hw_oscilloscope_channel_get_data_raw_value_range(m_handle, m_ch, min, zero, max);
        Library::checkLastStatusAndThrowOnError();
      }

      int64_t dataRawValueMin() const
      {
        const int64_t result = tiepie_hw_oscilloscope_channel_get_data_raw_value_min(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      int64_t dataRawValueZero() const
      {
        const int64_t result = tiepie_hw_oscilloscope_channel_get_data_raw_value_zero(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      int64_t dataRawValueMax() const
      {
        const int64_t result = tiepie_hw_oscilloscope_channel_get_data_raw_value_max(m_handle, m_ch);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isRangeMaxReachable() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_is_range_max_reachable(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasSureconnect() const
      {
        const bool result = tiepie_hw_oscilloscope_channel_has_sureconnect(m_handle, m_ch) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }
  };

  class Generator : public Device
  {
    public:
      Generator(Handle handle) :
        Device(handle)
      {
      }

      uint32_t connectorType() const
      {
        const uint32_t result = tiepie_hw_generator_get_connector_type(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isDifferential() const
      {
        const bool result = tiepie_hw_generator_is_differential(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double impedance() const
      {
        const double result = tiepie_hw_generator_get_impedance(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint8_t resolution() const
      {
        const uint8_t result = tiepie_hw_generator_get_resolution(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double outputValueMin() const
      {
        const double result = tiepie_hw_generator_get_output_value_min(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double outputValueMax() const
      {
        const double result = tiepie_hw_generator_get_output_value_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void getOutputValueMinMax(double* min, double* max) const
      {
        tiepie_hw_generator_get_output_value_min_max(m_handle, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      bool isControllable() const
      {
        const bool result = tiepie_hw_generator_is_controllable(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isRunning() const
      {
        const bool result = tiepie_hw_generator_is_running(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t status() const
      {
        const uint32_t result = tiepie_hw_generator_get_status(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool outputEnable() const
      {
        const bool result = tiepie_hw_generator_get_output_enable(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool setOutputEnable(bool value)
      {
        const bool result = tiepie_hw_generator_set_output_enable(m_handle, value ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasOutputInvert() const
      {
        const bool result = tiepie_hw_generator_has_output_invert(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool outputInvert() const
      {
        const bool result = tiepie_hw_generator_get_output_invert(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool setOutputInvert(bool value)
      {
        const bool result = tiepie_hw_generator_set_output_invert(m_handle, value ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void start()
      {
        tiepie_hw_generator_start(m_handle);
        Library::checkLastStatusAndThrowOnError();
      }

      void stop()
      {
        tiepie_hw_generator_stop(m_handle);
        Library::checkLastStatusAndThrowOnError();
      }

      uint32_t signalTypes() const
      {
        const uint32_t result = tiepie_hw_generator_get_signal_types(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t signalType() const
      {
        const uint32_t result = tiepie_hw_generator_get_signal_type(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t setSignalType(uint32_t value)
      {
        const uint32_t result = tiepie_hw_generator_set_signal_type(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasAmplitude() const
      {
        const bool result = tiepie_hw_generator_has_amplitude(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasAmplitude(uint32_t signal_type) const
      {
        const bool result = tiepie_hw_generator_has_amplitude_ex(m_handle, signal_type) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double amplitudeMin() const
      {
        const double result = tiepie_hw_generator_get_amplitude_min(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double amplitudeMax() const
      {
        const double result = tiepie_hw_generator_get_amplitude_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void getAmplitudeMinMax(uint32_t signal_type, double* min, double* max) const
      {
        tiepie_hw_generator_get_amplitude_min_max_ex(m_handle, signal_type, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      double amplitude() const
      {
        const double result = tiepie_hw_generator_get_amplitude(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setAmplitude(double amplitude)
      {
        const double result = tiepie_hw_generator_set_amplitude(m_handle, amplitude);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyAmplitude(double amplitude) const
      {
        const double result = tiepie_hw_generator_verify_amplitude(m_handle, amplitude);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyAmplitude(double amplitude, uint32_t signal_type, uint32_t amplitude_range_index, double offset, bool output_invert) const
      {
        const double result = tiepie_hw_generator_verify_amplitude_ex(m_handle, amplitude, signal_type, amplitude_range_index, offset, output_invert ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::vector<double> amplitudeRanges() const
      {
        const uint32_t length = tiepie_hw_generator_get_amplitude_ranges(m_handle, nullptr, 0);
        Library::checkLastStatusAndThrowOnError();
        std::vector<double> tmp(length);
        tiepie_hw_generator_get_amplitude_ranges(m_handle, tmp.data(), length);
        Library::checkLastStatusAndThrowOnError();
        return tmp;
      }

      double amplitudeRange() const
      {
        const double result = tiepie_hw_generator_get_amplitude_range(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setAmplitudeRange(double value)
      {
        const double result = tiepie_hw_generator_set_amplitude_range(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool amplitudeAutoRanging() const
      {
        const bool result = tiepie_hw_generator_get_amplitude_auto_ranging(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool setAmplitudeAutoRanging(bool value)
      {
        const bool result = tiepie_hw_generator_set_amplitude_auto_ranging(m_handle, value ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasOffset() const
      {
        const bool result = tiepie_hw_generator_has_offset(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasOffset(uint32_t signal_type) const
      {
        const bool result = tiepie_hw_generator_has_offset_ex(m_handle, signal_type) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double offsetMin() const
      {
        const double result = tiepie_hw_generator_get_offset_min(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double offsetMax() const
      {
        const double result = tiepie_hw_generator_get_offset_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void getOffsetMinMax(uint32_t signal_type, double* min, double* max) const
      {
        tiepie_hw_generator_get_offset_min_max_ex(m_handle, signal_type, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      double offset() const
      {
        const double result = tiepie_hw_generator_get_offset(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setOffset(double value)
      {
        const double result = tiepie_hw_generator_set_offset(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyOffset(double value) const
      {
        const double result = tiepie_hw_generator_verify_offset(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyOffset(double value, uint32_t signal_type, double amplitude, bool output_invert) const
      {
        const double result = tiepie_hw_generator_verify_offset_ex(m_handle, value, signal_type, amplitude, output_invert ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t frequencyModes() const
      {
        const uint32_t result = tiepie_hw_generator_get_frequency_modes(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t frequencyModes(uint32_t signal_type) const
      {
        const uint32_t result = tiepie_hw_generator_get_frequency_modes_ex(m_handle, signal_type);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t frequencyMode() const
      {
        const uint32_t result = tiepie_hw_generator_get_frequency_mode(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t setFrequencyMode(uint32_t value)
      {
        const uint32_t result = tiepie_hw_generator_set_frequency_mode(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasFrequency() const
      {
        const bool result = tiepie_hw_generator_has_frequency(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasFrequency(uint32_t frequency_mode, uint32_t signal_type) const
      {
        const bool result = tiepie_hw_generator_has_frequency_ex(m_handle, frequency_mode, signal_type) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double frequencyMin() const
      {
        const double result = tiepie_hw_generator_get_frequency_min(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double frequencyMax() const
      {
        const double result = tiepie_hw_generator_get_frequency_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void getFrequencyMinMax(uint32_t frequency_mode, double* min, double* max) const
      {
        tiepie_hw_generator_get_frequency_min_max(m_handle, frequency_mode, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      void getFrequencyMinMax(uint32_t frequency_mode, uint32_t signal_type, double* min, double* max) const
      {
        tiepie_hw_generator_get_frequency_min_max_ex(m_handle, frequency_mode, signal_type, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      double frequency() const
      {
        const double result = tiepie_hw_generator_get_frequency(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setFrequency(double value)
      {
        const double result = tiepie_hw_generator_set_frequency(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyFrequency(double value) const
      {
        const double result = tiepie_hw_generator_verify_frequency(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyFrequency(double value, uint32_t frequency_mode, uint32_t signal_type, uint64_t data_length, double width) const
      {
        const double result = tiepie_hw_generator_verify_frequency_ex(m_handle, value, frequency_mode, signal_type, data_length, width);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasPhase() const
      {
        const bool result = tiepie_hw_generator_has_phase(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasPhase(uint32_t signal_type) const
      {
        const bool result = tiepie_hw_generator_has_phase_ex(m_handle, signal_type) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double phaseMin() const
      {
        const double result = tiepie_hw_generator_get_phase_min(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double phaseMax() const
      {
        const double result = tiepie_hw_generator_get_phase_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void getPhaseMinMax(uint32_t signal_type, double* min, double* max) const
      {
        tiepie_hw_generator_get_phase_min_max_ex(m_handle, signal_type, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      double phase() const
      {
        const double result = tiepie_hw_generator_get_phase(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setPhase(double value)
      {
        const double result = tiepie_hw_generator_set_phase(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyPhase(double value) const
      {
        const double result = tiepie_hw_generator_verify_phase(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyPhase(double value, uint32_t signal_type) const
      {
        const double result = tiepie_hw_generator_verify_phase_ex(m_handle, value, signal_type);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasSymmetry() const
      {
        const bool result = tiepie_hw_generator_has_symmetry(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasSymmetry(uint32_t signal_type) const
      {
        const bool result = tiepie_hw_generator_has_symmetry_ex(m_handle, signal_type) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double symmetryMin() const
      {
        const double result = tiepie_hw_generator_get_symmetry_min(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double symmetryMax() const
      {
        const double result = tiepie_hw_generator_get_symmetry_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void getSymmetryMinMax(uint32_t signal_type, double* min, double* max) const
      {
        tiepie_hw_generator_get_symmetry_min_max_ex(m_handle, signal_type, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      double symmetry() const
      {
        const double result = tiepie_hw_generator_get_symmetry(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setSymmetry(double value)
      {
        const double result = tiepie_hw_generator_set_symmetry(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifySymmetry(double value) const
      {
        const double result = tiepie_hw_generator_verify_symmetry(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifySymmetry(double value, uint32_t signal_type) const
      {
        const double result = tiepie_hw_generator_verify_symmetry_ex(m_handle, value, signal_type);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasWidth() const
      {
        const bool result = tiepie_hw_generator_has_width(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasWidth(uint32_t signal_type) const
      {
        const bool result = tiepie_hw_generator_has_width_ex(m_handle, signal_type) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double widthMin() const
      {
        const double result = tiepie_hw_generator_get_width_min(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double widthMax() const
      {
        const double result = tiepie_hw_generator_get_width_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void widthMinMax(uint32_t signal_type, double signal_frequency, double* min, double* max) const
      {
        tiepie_hw_generator_get_width_min_max_ex(m_handle, signal_type, signal_frequency, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      double width() const
      {
        const double result = tiepie_hw_generator_get_width(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setWidth(double value)
      {
        const double result = tiepie_hw_generator_set_width(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyWidth(double value) const
      {
        const double result = tiepie_hw_generator_verify_width(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyWidth(double value, uint32_t signal_type, double signal_frequency) const
      {
        const double result = tiepie_hw_generator_verify_width_ex(m_handle, value, signal_type, signal_frequency);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasEdgeTime() const
      {
        const bool result = tiepie_hw_generator_has_edge_time(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasEdgeTime(uint32_t signal_type) const
      {
        const bool result = tiepie_hw_generator_has_edge_time_ex(m_handle, signal_type) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double leadingEdgeTimeMin() const
      {
        const double result = tiepie_hw_generator_get_leading_edge_time_min(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double leadingEdgeTimeMax() const
      {
        const double result = tiepie_hw_generator_get_leading_edge_time_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void getLeadingEdgeTimeMinMax(uint32_t signal_type, double signal_frequency, double symmetry, double width, double trailing_edge_time, double* min, double* max) const
      {
        tiepie_hw_generator_get_leading_edge_time_min_max_ex(m_handle, signal_type, signal_frequency, symmetry, width, trailing_edge_time, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      double leadingEdgeTime() const
      {
        const double result = tiepie_hw_generator_get_leading_edge_time(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setLeadingEdgeTime(double leading_edge_time)
      {
        const double result = tiepie_hw_generator_set_leading_edge_time(m_handle, leading_edge_time);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyLeadingEdgeTime(double leading_edge_time) const
      {
        const double result = tiepie_hw_generator_verify_leading_edge_time(m_handle, leading_edge_time);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyLeadingEdgeTime(double leading_edge_time, uint32_t signal_type, double signal_frequency, double symmetry, double width, double trailing_edge_time) const
      {
        const double result = tiepie_hw_generator_verify_leading_edge_time_ex(m_handle, leading_edge_time, signal_type, signal_frequency, symmetry, width, trailing_edge_time);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double trailingEdgeTimeMin() const
      {
        const double result = tiepie_hw_generator_get_trailing_edge_time_min(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double trailingEdgeTimeMax() const
      {
        const double result = tiepie_hw_generator_get_trailing_edge_time_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void getTrailingEdgeTimeMinMax(uint32_t signal_type, double signal_frequency, double symmetry, double width, double leading_edge_time, double* min, double* max) const
      {
        tiepie_hw_generator_get_trailing_edge_time_min_max_ex(m_handle, signal_type, signal_frequency, symmetry, width, leading_edge_time, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      double trailingEdgeTime() const
      {
        const double result = tiepie_hw_generator_get_trailing_edge_time(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double setTrailingEdgeTime(double value)
      {
        const double result = tiepie_hw_generator_set_trailing_edge_time(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyTrailingEdgeTime(double value) const
      {
        const double result = tiepie_hw_generator_verify_trailing_edge_time(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      double verifyTrailingEdgeTime(double trailing_edge_time, uint32_t signal_type, double signal_frequency, double symmetry, double width, double leading_edge_time) const
      {
        const double result = tiepie_hw_generator_verify_trailing_edge_time_ex(m_handle, trailing_edge_time, signal_type, signal_frequency, symmetry, width, leading_edge_time);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasData() const
      {
        const bool result = tiepie_hw_generator_has_data(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasData(uint32_t signal_type) const
      {
        const bool result = tiepie_hw_generator_has_data_ex(m_handle, signal_type) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t dataLengthMin() const
      {
        const uint64_t result = tiepie_hw_generator_get_data_length_min(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t dataLengthMax() const
      {
        const uint64_t result = tiepie_hw_generator_get_data_length_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void getDataLengthMinMax(uint32_t signal_type, uint64_t* min, uint64_t* max) const
      {
        tiepie_hw_generator_get_data_length_min_max_ex(m_handle, signal_type, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      uint64_t dataLength() const
      {
        const uint64_t result = tiepie_hw_generator_get_data_length(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t verifyDataLength(uint64_t value) const
      {
        const uint64_t result = tiepie_hw_generator_verify_data_length(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t verifyDataLength(uint64_t value, uint32_t signal_type) const
      {
        const uint64_t result = tiepie_hw_generator_verify_data_length_ex(m_handle, value, signal_type);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void setData(const float* buffer, uint64_t sample_count)
      {
        tiepie_hw_generator_set_data(m_handle, buffer, sample_count);
        Library::checkLastStatusAndThrowOnError();
      }

      void setData(const float* buffer, uint64_t sample_count, uint32_t signal_type)
      {
        tiepie_hw_generator_set_data_ex(m_handle, buffer, sample_count, signal_type);
        Library::checkLastStatusAndThrowOnError();
      }

      uint32_t dataRawType() const
      {
        const uint32_t result = tiepie_hw_generator_get_data_raw_type(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void dataRawValueRange(int64_t* min, int64_t* zero, int64_t* max) const
      {
        tiepie_hw_generator_get_data_raw_value_range(m_handle, min, zero, max);
        Library::checkLastStatusAndThrowOnError();
      }

      int64_t dataRawValueMin() const
      {
        const int64_t result = tiepie_hw_generator_get_data_raw_value_min(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      int64_t dataRawValueZero() const
      {
        const int64_t result = tiepie_hw_generator_get_data_raw_value_zero(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      int64_t dataRawValueMax() const
      {
        const int64_t result = tiepie_hw_generator_get_data_raw_value_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void setDataRaw(const void* buffer, uint64_t sample_count)
      {
        tiepie_hw_generator_set_data_raw(m_handle, buffer, sample_count);
        Library::checkLastStatusAndThrowOnError();
      }

      void setDataRaw(const void* buffer, uint64_t sample_count, uint32_t signal_type)
      {
        tiepie_hw_generator_set_data_raw_ex(m_handle, buffer, sample_count, signal_type);
        Library::checkLastStatusAndThrowOnError();
      }

      uint64_t modes() const
      {
        const uint64_t result = tiepie_hw_generator_get_modes(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t modes(uint32_t signal_type, uint32_t frequency_mode) const
      {
        const uint64_t result = tiepie_hw_generator_get_modes_ex(m_handle, signal_type, frequency_mode);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t modesNative() const
      {
        const uint64_t result = tiepie_hw_generator_get_modes_native(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t mode() const
      {
        const uint64_t result = tiepie_hw_generator_get_mode(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t setMode(uint64_t value)
      {
        const uint64_t result = tiepie_hw_generator_set_mode(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool isBurstActive() const
      {
        const bool result = tiepie_hw_generator_is_burst_active(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t burstCountMin() const
      {
        const uint64_t result = tiepie_hw_generator_get_burst_count_min(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t burstCountMax() const
      {
        const uint64_t result = tiepie_hw_generator_get_burst_count_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void burstCountMinMax(uint64_t generator_mode, uint64_t* min, uint64_t* max) const
      {
        tiepie_hw_generator_get_burst_count_min_max_ex(m_handle, generator_mode, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      uint64_t burstCount() const
      {
        const uint64_t result = tiepie_hw_generator_get_burst_count(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t setBurstCount(uint64_t value)
      {
        const uint64_t result = tiepie_hw_generator_set_burst_count(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t burstSampleCountMin() const
      {
        const uint64_t result = tiepie_hw_generator_get_burst_sample_count_min(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t burstSampleCountMax() const
      {
        const uint64_t result = tiepie_hw_generator_get_burst_sample_count_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void burstSampleCountMinMax(uint64_t generator_mode, uint64_t* min, uint64_t* max) const
      {
        tiepie_hw_generator_get_burst_sample_count_min_max_ex(m_handle, generator_mode, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      uint64_t burstSampleCount() const
      {
        const uint64_t result = tiepie_hw_generator_get_burst_sample_count(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t setBurstSampleCount(uint64_t value)
      {
        const uint64_t result = tiepie_hw_generator_set_burst_sample_count(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t burstSegmentCountMin() const
      {
        const uint64_t result = tiepie_hw_generator_get_burst_segment_count_min(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t burstSegmentCountMax() const
      {
        const uint64_t result = tiepie_hw_generator_get_burst_segment_count_max(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      void burstSegmentCountMinMax(uint64_t generator_mode, uint32_t signal_type, uint32_t frequency_mode, double frequency, uint64_t data_length, uint64_t* min, uint64_t* max) const
      {
        tiepie_hw_generator_get_burst_segment_count_min_max_ex(m_handle, generator_mode, signal_type, frequency_mode, frequency, data_length, min, max);
        Library::checkLastStatusAndThrowOnError();
      }

      uint64_t burstSegmentCount() const
      {
        const uint64_t result = tiepie_hw_generator_get_burst_segment_count(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t setBurstSegmentCount(uint64_t value)
      {
        const uint64_t result = tiepie_hw_generator_set_burst_segment_count(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t verifyBurstSegmentCount(uint64_t value) const
      {
        const uint64_t result = tiepie_hw_generator_verify_burst_segment_count(m_handle, value);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint64_t verifyBurstSegmentCount(uint64_t value, uint64_t generator_mode, uint32_t signal_type, uint32_t frequency_mode, double frequency, uint64_t data_length) const
      {
        const uint64_t result = tiepie_hw_generator_verify_burst_segment_count_ex(m_handle, value, generator_mode, signal_type, frequency_mode, frequency, data_length);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }
  };

  class DeviceListItem : public Object
  {
    public:
      DeviceListItem(Handle handle) :
        Object{handle}
      {
      }

      [[nodiscard]] std::unique_ptr<Device> openDevice(uint32_t device_type)
      {
        const Handle result = tiepie_hw_devicelistitem_open_device(m_handle, device_type);
        Library::checkLastStatusAndThrowOnError();

        switch(device_type)
        {
          case TIEPIE_HW_DEVICETYPE_OSCILLOSCOPE:
            return std::make_unique<Oscilloscope>(result);

          case TIEPIE_HW_DEVICETYPE_GENERATOR:
            return std::make_unique<Generator>(result);

          default:
            tiepie_hw_object_close(result);
            throw InvalidValueException();
        }
      }

      [[nodiscard]] std::unique_ptr<Oscilloscope> openOscilloscope()
      {
        const Handle result = tiepie_hw_devicelistitem_open_oscilloscope(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return std::make_unique<Oscilloscope>(result);
      }

      [[nodiscard]] std::unique_ptr<Generator> openGenerator()
      {
        const Handle result = tiepie_hw_devicelistitem_open_generator(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return std::make_unique<Generator>(result);
      }

      bool isDemo() const
      {
        const bool result = tiepie_hw_devicelistitem_is_demo(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool canOpen(uint32_t device_type) const
      {
        const bool result = tiepie_hw_devicelistitem_can_open(m_handle, device_type) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::string openedBy(uint32_t device_type) const
      {
        const uint32_t length = tiepie_hw_devicelistitem_opened_by(m_handle, device_type, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_devicelistitem_opened_by(m_handle, device_type, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      tiepie_hw_productid productId() const
      {
        const tiepie_hw_productid result = tiepie_hw_devicelistitem_get_product_id(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::string name() const
      {
        const uint32_t length = tiepie_hw_devicelistitem_get_name(m_handle, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_devicelistitem_get_name(m_handle, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      std::string nameShort() const
      {
        const uint32_t length = tiepie_hw_devicelistitem_get_name_short(m_handle, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_devicelistitem_get_name_short(m_handle, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      std::string nameShortest() const
      {
        const uint32_t length = tiepie_hw_devicelistitem_get_name_shortest(m_handle, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_devicelistitem_get_name_shortest(m_handle, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      tiepie_hw_date calibrationDate() const
      {
        const tiepie_hw_date result = tiepie_hw_devicelistitem_get_calibration_date(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      uint32_t serialNumber() const
      {
        const uint32_t result = tiepie_hw_devicelistitem_get_serial_number(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      std::string ipAddress() const
      {
        const uint32_t length = tiepie_hw_devicelistitem_get_ip_address(m_handle, nullptr, 0) + 1;
        Library::checkLastStatusAndThrowOnError();
        std::unique_ptr<char[]> s = std::make_unique<char[]>(length);
        tiepie_hw_devicelistitem_get_ip_address(m_handle, s.get(), length);
        Library::checkLastStatusAndThrowOnError();
        return s.get();
      }

      uint16_t ipPort() const
      {
        const uint16_t result = tiepie_hw_devicelistitem_get_ip_port(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      bool hasServer() const
      {
        const bool result = tiepie_hw_devicelistitem_has_server(m_handle) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      [[nodiscard]] std::unique_ptr<Server> server() const
      {
        const Handle result = tiepie_hw_devicelistitem_get_server(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return std::make_unique<Server>(result);
      }

      uint32_t types() const
      {
        const uint32_t result = tiepie_hw_devicelistitem_get_types(m_handle);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }
  };

  class DeviceList
  {
    public:
      [[nodiscard]] static std::unique_ptr<DeviceListItem> getItemByProductId(tiepie_hw_productid productId)
      {
        const Handle handle = tiepie_hw_devicelist_get_item_by_product_id(productId);
        Library::checkLastStatusAndThrowOnError();
        return std::make_unique<DeviceListItem>(handle);
      }

      [[nodiscard]] static std::unique_ptr<DeviceListItem> getItemByIndex(uint32_t index)
      {
        const Handle handle = tiepie_hw_devicelist_get_item_by_index(index);
        Library::checkLastStatusAndThrowOnError();
        return std::make_unique<DeviceListItem>(handle);
      }

      [[nodiscard]] static std::unique_ptr<DeviceListItem> getItemBySerialNumber(uint32_t serialNumber)
      {
        const Handle handle = tiepie_hw_devicelist_get_item_by_serial_number(serialNumber);
        Library::checkLastStatusAndThrowOnError();
        return std::make_unique<DeviceListItem>(handle);
      }

      static void update()
      {
        tiepie_hw_devicelist_update();
        Library::checkLastStatusAndThrowOnError();
      }

      static bool usbHotplugDetectEnabled()
      {
        const bool result = tiepie_hw_devicelist_get_usb_hotplug_detect_enabled() != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      static bool setUsbHotplugDetectEnabled(bool value)
      {
        const bool result = tiepie_hw_devicelist_set_usb_hotplug_detect_enabled(value ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE) != TIEPIE_HW_BOOL_FALSE;
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      static uint32_t count()
      {
        const uint32_t result = tiepie_hw_devicelist_get_count();
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      static const tiepie_hw_demo_info* demoDeviceInfo()
      {
        const tiepie_hw_demo_info* result = tiepie_hw_devicelist_get_demo_device_info();
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      static uint32_t createDemoDevice(tiepie_hw_productid product_id)
      {
        const uint32_t result = tiepie_hw_devicelist_create_demo_device(product_id);
        Library::checkLastStatusAndThrowOnError();
        return result;
      }

      [[nodiscard]] static std::unique_ptr<DeviceListItem> createCombinedDevice(const std::vector<std::unique_ptr<Oscilloscope>>& devices)
      {
        std::vector<Handle> handles;
        handles.reserve(devices.size());

        for(const auto& device : devices)
        {
          if(!device)
            throw InvalidValueException();

          handles.emplace_back(device->handle());
        }

        const uint32_t serialNumber = tiepie_hw_devicelist_create_combined_device(handles.data(), handles.size());
        Library::checkLastStatusAndThrowOnError();
        return getItemBySerialNumber(serialNumber);
      }

      [[nodiscard]] static std::unique_ptr<Device> createAndOpenCombinedDevice(const std::vector<std::unique_ptr<Device>>& devices)
      {
        std::vector<Handle> handles;
        handles.reserve(devices.size());

        for(const auto& device : devices)
        {
          if(!device)
            throw InvalidValueException();

          handles.emplace_back(device->handle());
        }

        const Handle result = tiepie_hw_devicelist_create_and_open_combined_device(handles.data(), handles.size());
        Library::checkLastStatusAndThrowOnError();

        const uint32_t device_type = tiepie_hw_device_get_type(result);
        Library::checkLastStatusAndThrowOnError();

        switch(device_type)
        {
          case TIEPIE_HW_DEVICETYPE_OSCILLOSCOPE:
            return std::make_unique<Oscilloscope>(result);

          case TIEPIE_HW_DEVICETYPE_GENERATOR:
            return std::make_unique<Generator>(result);

          default:
            tiepie_hw_object_close(result);
            throw InvalidValueException();
        }
      }

      [[nodiscard]] static std::unique_ptr<Oscilloscope> createAndOpenCombinedOscilloscope(const std::vector<std::unique_ptr<Oscilloscope>>& devices)
      {
        std::vector<Handle> handles;
        handles.reserve(devices.size());

        for(const auto& device : devices)
        {
          if(!device)
            throw InvalidValueException();

          handles.emplace_back(device->handle());
        }

        const Handle result = tiepie_hw_devicelist_create_and_open_combined_device(handles.data(), handles.size());
        Library::checkLastStatusAndThrowOnError();
        return std::make_unique<Oscilloscope>(result);
      }

      static void removeDevice(uint32_t serial_number, bool force)
      {
        tiepie_hw_devicelist_remove_device(serial_number, force ? TIEPIE_HW_BOOL_TRUE : TIEPIE_HW_BOOL_FALSE);
        Library::checkLastStatusAndThrowOnError();
      }

      static void removeUnusedDevices()
      {
        tiepie_hw_devicelist_remove_unused_devices();
        Library::checkLastStatusAndThrowOnError();
      }

      static void setCallbackDeviceAdded(tiepie_hw_devicelist_callback callback, void* data)
      {
        tiepie_hw_devicelist_set_callback_device_added(callback, data);
        Library::checkLastStatusAndThrowOnError();
      }

      static void setCallbackDeviceRemoved(tiepie_hw_devicelist_callback callback, void* data)
      {
        tiepie_hw_devicelist_set_callback_device_removed(callback, data);
        Library::checkLastStatusAndThrowOnError();
      }

      static void setCallbackDeviceCanOpenChanged(tiepie_hw_devicelist_callback callback, void* data)
      {
        tiepie_hw_devicelist_set_callback_device_can_open_changed(callback, data);
        Library::checkLastStatusAndThrowOnError();
      }
  };
}

#endif
