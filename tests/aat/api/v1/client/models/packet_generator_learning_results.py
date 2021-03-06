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


class PacketGeneratorLearningResults(object):
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
        'resolved_state': 'str',
        'ipv4': 'list[PacketGeneratorLearningResultIpv4]',
        'ipv6': 'list[PacketGeneratorLearningResultIpv6]'
    }

    attribute_map = {
        'resolved_state': 'resolved_state',
        'ipv4': 'ipv4',
        'ipv6': 'ipv6'
    }

    def __init__(self, resolved_state=None, ipv4=None, ipv6=None):  # noqa: E501
        """PacketGeneratorLearningResults - a model defined in Swagger"""  # noqa: E501

        self._resolved_state = None
        self._ipv4 = None
        self._ipv6 = None
        self.discriminator = None

        self.resolved_state = resolved_state
        if ipv4 is not None:
            self.ipv4 = ipv4
        if ipv6 is not None:
            self.ipv6 = ipv6

    @property
    def resolved_state(self):
        """Gets the resolved_state of this PacketGeneratorLearningResults.  # noqa: E501

        Indicates current learning state.   # noqa: E501

        :return: The resolved_state of this PacketGeneratorLearningResults.  # noqa: E501
        :rtype: str
        """
        return self._resolved_state

    @resolved_state.setter
    def resolved_state(self, resolved_state):
        """Sets the resolved_state of this PacketGeneratorLearningResults.

        Indicates current learning state.   # noqa: E501

        :param resolved_state: The resolved_state of this PacketGeneratorLearningResults.  # noqa: E501
        :type: str
        """
        self._resolved_state = resolved_state

    @property
    def ipv4(self):
        """Gets the ipv4 of this PacketGeneratorLearningResults.  # noqa: E501

        List of IPv4 address and their associated MAC addresses.  # noqa: E501

        :return: The ipv4 of this PacketGeneratorLearningResults.  # noqa: E501
        :rtype: list[PacketGeneratorLearningResultIpv4]
        """
        return self._ipv4

    @ipv4.setter
    def ipv4(self, ipv4):
        """Sets the ipv4 of this PacketGeneratorLearningResults.

        List of IPv4 address and their associated MAC addresses.  # noqa: E501

        :param ipv4: The ipv4 of this PacketGeneratorLearningResults.  # noqa: E501
        :type: list[PacketGeneratorLearningResultIpv4]
        """
        self._ipv4 = ipv4

    @property
    def ipv6(self):
        """Gets the ipv6 of this PacketGeneratorLearningResults.  # noqa: E501

        List of IPv6 destinations, IPv6 next hop, and next hop MAC addresses.  # noqa: E501

        :return: The ipv6 of this PacketGeneratorLearningResults.  # noqa: E501
        :rtype: list[PacketGeneratorLearningResultIpv6]
        """
        return self._ipv6

    @ipv6.setter
    def ipv6(self, ipv6):
        """Sets the ipv6 of this PacketGeneratorLearningResults.

        List of IPv6 destinations, IPv6 next hop, and next hop MAC addresses.  # noqa: E501

        :param ipv6: The ipv6 of this PacketGeneratorLearningResults.  # noqa: E501
        :type: list[PacketGeneratorLearningResultIpv6]
        """
        self._ipv6 = ipv6

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
        if issubclass(PacketGeneratorLearningResults, dict):
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
        if not isinstance(other, PacketGeneratorLearningResults):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other
