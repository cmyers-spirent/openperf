# coding: utf-8

"""
    OpenPerf API

    REST API interface for OpenPerf  # noqa: E501

    OpenAPI spec version: 1
    Contact: support@spirent.com
    Generated by: https://github.com/swagger-api/swagger-codegen.git
"""


import pprint
import re  # noqa: F401

import six


class InterfaceProtocolConfigIpv6Dhcp6(object):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """

    """
    Attributes:
      swagger_types (dict): The key is attribute name
                            and the value is attribute type.
      attribute_map (dict): The key is attribute name
                            and the value is json key in definition.
    """
    swagger_types = {
        'stateless': 'bool'
    }

    attribute_map = {
        'stateless': 'stateless'
    }

    def __init__(self, stateless=True):  # noqa: E501
        """InterfaceProtocolConfigIpv6Dhcp6 - a model defined in Swagger"""  # noqa: E501

        self._stateless = None
        self.discriminator = None

        self.stateless = stateless

    @property
    def stateless(self):
        """Gets the stateless of this InterfaceProtocolConfigIpv6Dhcp6.  # noqa: E501

        Stateless DHCPv6  # noqa: E501

        :return: The stateless of this InterfaceProtocolConfigIpv6Dhcp6.  # noqa: E501
        :rtype: bool
        """
        return self._stateless

    @stateless.setter
    def stateless(self, stateless):
        """Sets the stateless of this InterfaceProtocolConfigIpv6Dhcp6.

        Stateless DHCPv6  # noqa: E501

        :param stateless: The stateless of this InterfaceProtocolConfigIpv6Dhcp6.  # noqa: E501
        :type: bool
        """
        self._stateless = stateless

    def to_dict(self):
        """Returns the model properties as a dict"""
        result = {}

        for attr, _ in six.iteritems(self.swagger_types):
            value = getattr(self, attr)
            if isinstance(value, list):
                result[attr] = list(map(
                    lambda x: x.to_dict() if hasattr(x, "to_dict") else x,
                    value
                ))
            elif hasattr(value, "to_dict"):
                result[attr] = value.to_dict()
            elif isinstance(value, dict):
                result[attr] = dict(map(
                    lambda item: (item[0], item[1].to_dict())
                    if hasattr(item[1], "to_dict") else item,
                    value.items()
                ))
            else:
                result[attr] = value
        if issubclass(InterfaceProtocolConfigIpv6Dhcp6, dict):
            for key, value in self.items():
                result[key] = value

        return result

    def to_str(self):
        """Returns the string representation of the model"""
        return pprint.pformat(self.to_dict())

    def __repr__(self):
        """For `print` and `pprint`"""
        return self.to_str()

    def __eq__(self, other):
        """Returns true if both objects are equal"""
        if not isinstance(other, InterfaceProtocolConfigIpv6Dhcp6):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other